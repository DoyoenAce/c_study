#include<stdio.h>
int main(void)
{
    char word[200];
    char maximum = 0;
    printf("영단어를 입력하세요 : ");
    scanf("%s", word);
    for(int i = 0; i < 200; i++)
    {
        if(word[i] == '\0')
        {
            break;
        }
        if(word[i] > maximum)
        {
            maximum = word[i];
        }
        
    }
    printf("%c\n", maximum);

    return 0;
}