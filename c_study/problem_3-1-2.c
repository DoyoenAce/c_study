#include<stdio.h>
int main(void)
{
    int num1, num2, num3;
    int result;
    printf("3 개의 정수를 입력해세요;");
    scanf("%d %d %d", &num1, &num2, &num3);
    result = num1*num2+num3;
    printf("%d x %d + %d = %d \n", num1, num2, num3, result);
    return 0;
}