#include<stdio.h>
int main(void)
{
    for(int i = 0; i <= 9; i++)
    {
        int g = 1;
        scanf("%d", &g);
        printf("%d * %d = %d\n", g, 1, g*1);
        printf("%d * %d = %d\n", g, 2, g*2);
        printf("%d * %d = %d\n", g, 3, g*3);
        printf("%d * %d = %d\n", g, 4, g*4);
        printf("%d * %d = %d\n", g, 5, g*5);
        printf("%d * %d = %d\n", g, 6, g*6);
        printf("%d * %d = %d\n", g, 7, g*7);
        printf("%d * %d = %d\n", g, 8, g*8);
        printf("%d * %d = %d\n", g, 9, g*9);
    }
    return 0;

}