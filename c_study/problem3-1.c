#include <stdio.h>
int main(void)
{
    int num1, num2;
    printf("정수 두 개 입력:");
    scanf("%d,%d", &num1, &num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d x %d = %d", num1, num2, num1*num2);
    return 0 ;
}