#include<stdio.h>
int main(void)
{
    int a, b;
    int c[5];
    for(int i=0; i<5; i++)
    {
        scanf("%d %d", &a, &b);
        c[i]=a+b;
    }
    for (int i=0; i<5; i++)
    {
        printf("%d\n", c[i]);
    }
    return 0;
}