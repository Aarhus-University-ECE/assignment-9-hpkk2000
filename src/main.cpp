extern "C"{
    #include "sum.c"
    #include <stdio.h>
    #include "search.c"
    #include "dfs.h"
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    //sum test
    int a[10] = {1,99,1,1,1,1,1,1,1,1};
    int s = sum(a,10);
    printf("%d",s);

    //search test
    int a1[10] = {2,3423,42,234,3456,3,3456,234,8,10};
    int x = 3;
    printf("%d",search(a1,10,x));

    //dfs test
    node *root = make_node(4,make_node(7,make_node(28,make_node(77,NULL,NULL),make_node(23,NULL,NULL)),make_node(86,make_node(3,NULL,NULL),make_node(9,NULL,NULL))),make_node(98,NULL,NULL));
    DFT(root);
    return 0;
}