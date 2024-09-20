#include<stdio.h>
int main(void)
{
    int num1 =10, num2 = 20;
    int * ptr1 = &num1;
    int * ptr2 = &num2;
    int * temp;
    printf("기존 변수 값: %d %d \n", *ptr1, *ptr2);
    
    (*ptr1) += 10;
    (*ptr2) -= 10;
    printf("10 씩 더하고 뺀 변수 값: %d %d \n", *ptr1, *ptr2);

    temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
    printf("각각 바꾼 변수 값: %d %d \n", *ptr1, *ptr2);
    return 0;
}