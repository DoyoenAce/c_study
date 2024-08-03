#include <stdio.h>
int main (void)
{
    int a, b, c;
    scanf("%d %d ", &a, &b);
    scanf("%d", &c);
    if (b+c >= 60)
    {
        a = a+((b+c)/60);
        b = (b+c) % 60;
        if (a>=24)
        {
            a = a%24;
        }
    }
    else
    {
        b = b+c;
    }
    printf("%d %d", a, b);
    return 0;
}