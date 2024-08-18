#include<stdio.h>
int main(void)
{
    int a, b, c;
    scanf("%d", &c);
    for(a=0; a< c; a++)
    {
        for(b=0; b<c-1-a; b++)
        {
            printf(" ");
        }
        for(b=0; b<a+1; b++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}