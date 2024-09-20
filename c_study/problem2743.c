#include<stdio.h>
int main(void)
{
    char word[101];
    scanf("%s", word);
    int num=0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        num++;
    }
    printf("%d", num);
    return 0;
}