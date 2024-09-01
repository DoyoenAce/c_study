#include<stdio.h>
int main(void)
{
    int arr[5];
    int max, min, sum, i;
    for(i=0; i<5; i++)
    {
        printf("정수를 입력하세요:");
        scanf("%d", &arr[i]);
    }
    
    max = min = sum = arr[0];
    for(i=1; i<5; i++)
    {
        sum += arr[i];
        if(max<arr[i])
        {
            max = arr[i];
        }
        if(min>arr[i])
        {
            min = arr[i];
        }

    }
    printf("최댓값: %d \n", max);
    printf("최소값: %d \n", min);
    printf("합계: %d \n", sum);
    return 0;

}