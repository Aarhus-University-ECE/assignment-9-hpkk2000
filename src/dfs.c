#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"

typedef struct node
{
  int num;
  bool visited;
  struct node *rchild;
  struct node *lchild;
} node;

typedef struct stack
{
  struct node *node;
  struct stack *next;
} stack;

node *make_node (int num, node * left, node * right)
{
  node *n = malloc(sizeof(node));
  n->num = num;
  n->rchild = right;
  n->lchild = left;
  return n;
}

void free_node (node * p)
{
	
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{
  stack *temp = malloc(sizeof(stack));
  temp->node = node;
  temp->next = topp;
  return temp;
}

bool isEmpty (stack * topp)
{
  if (topp ==  NULL) {
    return true;
  } else {
    return false;
  }
}

node *top (stack * topp)
{
	return topp->node;
}

stack *pop (stack * topp)
{
	stack *temp;
  if (!isEmpty(topp)) {
    temp = topp;
    topp = topp->next;
  }
  free(temp);
  return topp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}

void DFT (node * root)
{
	stack *stck = NULL; //Create empty stack
  stck = push(stck,root); //push root to stack
  while (!isEmpty(stck)) { //continue while stack isnt empty
    node *x = top(stck); //get top element of stack (currently visiting )
    stck = pop(stck); //remove that element from stack
    if (x->rchild != NULL) { //if end of branch isnt reached
      stck = push(stck,x->rchild); //add children of current to stack
    }
    if (x->lchild != NULL) {
      stck = push(stck,x->lchild);
    }
    printf(" ");
    print_node(x); //print current element
  }

}