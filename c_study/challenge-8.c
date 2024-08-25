#include<stdio.h>
int square(int a)
{
    static int b=1;
    if(a==0)
    {
        return b;
    }
    b*=2;
    square(a-1);
}
int main(void)
{
    int num;
    scanf("%d", &num);
    printf("%d", square(num));
    return 0;
}