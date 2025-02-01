#include<stdio.h>
int main(void)
{
    int a, b, temp;
    scanf("%d %d", &a,&b);

    if (a>b)
    {
        temp = a;
        a = b;
        b = temp;
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