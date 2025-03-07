#include<stdio.h>
int main(void)
{
    int a, b,c;
    scanf("%d %d %d", &a, &b, &c); 
    if(a>b)
    {
        c = a;
        a = b;
        c = b;
    }
    for(int i= a; i<=b; i++)
    {
        for(int j = 1; j<=9; i++)
        {
            printf("%d x %d = %d\n", i, j, i*j);
        }
        printf("\n");
    }
    return 0;
}