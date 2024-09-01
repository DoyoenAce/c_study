#include<stdio.h>
int main(void)
{
    char word[100];
    int len = 0, i;
    char oppo;

    printf("영단어를 입력하세요:");
    scanf("%s", word);

    while(word[len] != '\0')
    {
        len++;
    }
    for(i = 0; i<len/2; i++)
    {
        oppo = word[i];
        word[i] = word[(len-i)-1];
        word[(len-i)-1] = oppo;
    }
    printf("뒤집은 결과: %s \n", word );
    return 0;
}