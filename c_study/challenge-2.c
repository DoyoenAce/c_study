#include<stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a,&b, &c);

    if (a>b)
    {
        c=a;
        a=b;
        b=c;
    }
    for (int i=a; i<=b; i++)
    {
        for(int d=1; d<=9; d++)
        {
            printf("%d x %d = %d\n", i, d, i*d);
        }
        printf("\n");
    }
    return 0;
}