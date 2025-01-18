#include<stdio.h>
void selectionsort(int ary[], int len);
int main(void)
{
    int arr[4];
    int i;
    for(i=0; i<4; i++)
    {
        printf("입력 %d:", i);
        scanf("%d", &arr[i]); //숫자 입력 받기
    }
    selectionsort(arr,sizeof(arr)/sizeof(int));
    for(i = 0; i<4; i++) //입력받을 개수 정하기기
    {
        printf("%d", arr[i]); //입력받은 값 프린트트
    }
    printf("\n");//한 줄 띄우고
    return 0;
}
void selectionsort(int arr[], int len)
{
    int i,j,temp;
    for(i = 0; i<len; i++)
    {
        int min =i;
        for(j =i; j<len; j++)//이 과정 반복하기기
        {
            if(arr[min]>arr[j]) //만약 min보다 j가 작다면 둘이 자리 바꾸기
            {
                min =j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

    }
}