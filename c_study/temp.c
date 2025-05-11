#include<stdio.h>
typedef struct temp
{
    int a;
} temp;

int first(int one)
{
    one = 1;
    printf("%d\n", one);
}

int main(void)
{
    
    int a = 0;
    first(a);
    return a;
}