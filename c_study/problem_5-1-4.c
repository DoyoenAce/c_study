#include<stdio.h>

int main(void)
{
    int asciicode;
    printf("숫자를 입력하세요:");
    scanf("%d", &asciicode);
    printf("아스키코드 문자: %c \n", asciicode);
    return 0;
}