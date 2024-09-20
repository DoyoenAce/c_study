#include<stdio.h>
#include<string.h>
int main(void)
{
    int n;
    char s[101];

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", s);
        printf("%c%c\n", s[0], s[strlen(s) - 1]);
    
    }
    return 0;
}