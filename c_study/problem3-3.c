#include <stdio.h>

int main(void)
{
    int num;
    printf("정수를 입력하세요:");
    scanf("%d", &num);
    printf("%d의 제곱의 결과입니다: %d \n", num, num*num);
    return 0;
}