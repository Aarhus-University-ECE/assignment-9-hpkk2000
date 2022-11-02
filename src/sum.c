#include "sum.h"
#include <assert.h>

int sum(int a[], int n)
{
    assert(n >= 0); /*Precondition*/
    if (n == 0)     /*Base case*/
    {
        return 0;
    }
    else /*Recursive step*/
    {
        return a[n - 1] + sum(a, n - 1);
    }
}