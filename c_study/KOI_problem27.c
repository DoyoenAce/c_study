#include<stdio.h>
int f(int x, int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
        return x*f(x, n-1);
    }
}

