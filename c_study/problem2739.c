#include <stdio.h>
int main(void)
{
    int a;
    int t;
    scanf("%d", &a);

    for (t=1;t<=9;t++)
    {
        printf("%d * %d = %d\n", a, t, a*t);
    }
    return 0;
}