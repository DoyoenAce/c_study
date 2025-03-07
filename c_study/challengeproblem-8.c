#include<stdio.h>
int fac(int n)
{
    if(n <= 1)
    {
        return 1;
    }
    else
    {
        return n*fac(n-1);
    }
}
int square(int n)
{
    if(n <= 0)
    {
        return 1;
    }
    else
    {
        return 2*square(n-1);
    }

}
int main(void)
{
    int n;
    scanf("%d", &n);
    int r = square(n);
    printf("%d\n", r);
}

