#include <stdio.h>
int main(void)
{
    int arr[5]={10, 3, 15, 12, 1};
    int temp;  
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp; 
            }
        }
    }
    
    for(int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}