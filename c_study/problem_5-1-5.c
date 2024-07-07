#include <stdio.h>
int main(void)
{
    char ch;
    printf("아스키코드 문자 입력:");
    scanf("%c", &ch);
    printf("아스키코드 변환 값: %d \n", ch);
    return 0;
}