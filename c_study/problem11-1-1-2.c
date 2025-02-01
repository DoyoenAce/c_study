#include<stdio.h>
int main(void)
{
    int arr[4];
    int max, min, i, sum;

    for(i = 0; i < 4; i++)
    {
        printf("숫자를 입력하세요: ");
        scanf("%d", &arr[i]);
    }
    max, min = arr[0];
    sum = 0;
    for(i = 0; i<4; i++)
    {
        sum += arr[i];
        if(min > arr[i])
        {
            min = arr[i];
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    printf("minimum number : %d\n", min);
    printf("maximum number : %d\n", max);
    printf("the sum : %d\n", sum);
    return 0;
}