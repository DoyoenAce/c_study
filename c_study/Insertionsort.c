#include<stdio.h>

void printArr(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    int N;
    scanf("%d", &N);
    int i,j,temp;
    int* arr;
    arr = malloc(sizeof(int)*N);
    for(i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    for(i = 1; i<N; i++)
    {
        for(j = i; j > 0; j--)        
        {
            if(arr[j-1] >= arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
            else
            {
                break;
            }
        }
    }

    printArr(arr, N);

    return 0;
}