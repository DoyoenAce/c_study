#include<stdio.h>
int main(void)
{
    int arr[4];
    int i;
    for(i=0; i<4; i++)
    {
        printf("입력 %d:", i);
        scanf("%d", &arr[i]);
    }
    insertionsort(arr,sizeof(arr)/sizeof(int));
    for(i = 0; i<4; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
void insertionsort(int arr[], int len)
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