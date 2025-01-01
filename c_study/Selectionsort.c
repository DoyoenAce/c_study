#include<stdio.h>
void selectionsort(int ary[], int len);
int main(void)
{
    int arr[4];
    int i;
    for(i=0; i<4; i++)
    {
        printf("입력 %d:", i);
        scanf("%d", &arr[i]);
    }
    selectionsort(arr,sizeof(arr)/sizeof(int));
    for(i = 0; i<4; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
void selectionsort(int arr[], int len)
{
    int i,j,temp;
    for(i = 0; i<len; i++)
    {
        int min =i;
        for(j =i; j<len; j++)
        {
            if(arr[min]>arr[j])
            {
                min =j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;

    }
}