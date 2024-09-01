#include <stdio.h>
int main(void)
{
    char word[100];
    int len = 0, i;
    char max = 0;
    printf("영단어를 입력하세요:");
    scanf("%s", word);

    while(word[len] != '\0')
    {
        len++;
    }

    for(i=0; i<len; i++)
    {
        if(max<word[i])
        {
            max = word[i];
        }
    }
    printf("가장 큰 아스키코드 값을 가지고 있는 문자는 %c입니다. \n", max);
    return 0;
}