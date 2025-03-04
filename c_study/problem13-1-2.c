#include<stdio.h>
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = arr;
    int a;
    for(a=0; a<5; a++)
    {
        int temp;
        *ptr += 2;
        printf("%d\n", arr[a]);
    }
    return 0;
}