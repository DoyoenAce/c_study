#include<stdio.h>
int main(void)
{
    int arr[4];
    int temp;
    arr[0] = temp;
    arr[0] = arr[2];
    temp = arr[2];
    arr[2] = temp;
    arr[2] = arr[3];
    temp = arr[3];
    printf("%ls", arr);
    return 0;

}