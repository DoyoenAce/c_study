#include<stdio.h>
int main(void)
{
    char word[100];
    int len = 0;
    printf("영단어를 입력하세요: ");
    scanf("%s", word);

    while(word[len] != 0)
    {
        len++;
    }
    printf("입력한 영단어는 %d 자 입니다. \n", len);
    return 0;
}