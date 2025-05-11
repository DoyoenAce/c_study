#include<stdio.h>
int main(void)
{
    int pal[30];

    for(int i = 0 ; i < 30; i++)
    {
        pal[i] = i % 10;
    }
    for (int i = 1; i < 30; i++) 
    {
        if (pal[0] == pal[i] && pal[1] == pal[i-1])
        {
            printf("%d\n", 0);
        }
        else if (pal[0] == pal[i] && pal[1] != pal[i-1])
        {
            printf("%d\n", 1);
        }
        else
        {
            printf("%d\n", 2);
        }
    }
    return 0;
}