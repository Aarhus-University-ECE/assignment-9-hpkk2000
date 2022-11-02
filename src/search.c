#include "search.h"
#include <stdbool.h>
#include <assert.h>

bool search(int a[], int n, int x)
{
    assert(n >= 0);             /*precondition*/
    if (n > 0 && a[n - 1] == x) /*base case*/
    {
        return true;
    }
    else if (n > 0 && a[n - 1] != x) /*recursive step*/
    {
        return search(a, n - 1, x);
    }
    else /*base case (n == 0)*/
    {
        return false;
    }
}