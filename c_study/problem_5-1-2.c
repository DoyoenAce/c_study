#include <stdio.h>
int main(void)
{
    double num1, num2;
    printf("2개의 정수를 입력해세요:");
    scanf("%lf %lf", &num1, &num2);

    printf("덧셈의 결과: %f \n", num1+num2);
    printf("뺄셈의 결과: %f \n", num1-num2);
    printf("곱셈의 결과: %f \n", num1*num2);
    printf("나눗셈의 결과: %f \n", num1/num2);
    return 0;
}