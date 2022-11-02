/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
  printf("TREE: \n");
  print_tree(root, 0);
  printf("\nDFS USING STACK: \n");


  //Make stack
  stack *stack = malloc(sizeof(stack));
  node *temp = root;



  //ALT KODE MED STACK

  //Push root node
  printf("%d",root->num);
  stack = push(stack, root);
  temp->visited = true;
  bool done = false;

  //Looper indtil min condition (stack->next->node==root && root->rchild->visited == true) er mødt
  while (!done) {

  //Går så langt til venstre som muligt af træet. Printer, pusher og markerer som alle på vegen som besøgt.
  while (temp->lchild != NULL) {
    temp=temp->lchild;
    printf(", %d", temp->num);
    stack = push(stack, temp);

    //Visited markerer om et node er blevet besøgt. Hvis den er besøgt, så skal den betragtes som en leaf node af sin parent.
    temp->visited=true;
  }

  //
  //Tjekker om hvorvidt en node har definerede child noder som den mangler at undersøge. Hvis ikke, skal den finde sin egen parent node, og temp skal pege derhen.
  while ((temp->lchild == NULL || temp->lchild->visited == true) && (temp->rchild == NULL || temp->rchild->visited == true) ) {
  
    //I tilfældet hvor vi er tilbage ved root af træet, skal right child undersøges. Hvis den er besøgt allerede er vi færdige.
    if (stack->next->node==root && root->rchild->visited == true) {
      done = true;
    }
    stack=pop(stack);
    temp=stack->node;

  if (done) {
    break;
  }

  }

if (done) {
    break;
  }
  

  temp=temp->rchild;
  printf(", %d",temp->num);
  stack = push(stack, temp);
  temp->visited=true;

  }

  printf("\n");

}

node *make_node (int num, node * left, node * right)
{
  node *treePtr = malloc(sizeof(node));

  //Laver en node med num, left og right child, og en status om den er besøgt eller ej.
  (treePtr)->num=num;
  (treePtr)->visited=false;
  (treePtr)->lchild = left;  
  (treePtr)->rchild = right;

  return treePtr;
}

void free_node (node * p) {
  free(p);
}


void print_node (node * p)
{
  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}

//Giver segentation fejl, så benytter mig ikke af den.
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

//Det sidste tilføjede (pushede) node i stacken bliver placeret i starten af stacken. Så er parent node, til noden vi undersøger i temp, først i stacken.
stack *push (stack * topp, node * node) {

  stack *t = malloc(sizeof(stack));

  t->next=topp;
  t->node=node;

  return t;
}

bool isEmpty (stack * topp)
{
  
}

node *top (stack * topp)
{
	
}

// Utility function to pop topp  
// element from the stack 

//Popper den første node i stacken, og returnerer noden efter. Denne returnerede pointer peger på parent node i træet. Denne bruges til at finde tilbage.)
stack *pop (stack * topp)
{
  stack *temp = topp;
  topp = topp->next;
  free(temp);

  return topp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      
      temp = temp->next;
    }

  printf ("====\n");

  return;
}