#include<stdio.h>
int main(void)
{
    int arr[5];
    int sum = 0, i;

    arr[0] = 10, arr[1] = 20, arr[2] = 30, arr[3] = 40, arr[4] = 50;

    for(i = 0; i<5; i++)
    {
        sum += arr[i];
    }
    printf("배열요소에 저장된 값의 합: %d \n", sum);
    return 0;
}