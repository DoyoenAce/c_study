#include<stdio.h>
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int* ptr = &arr[4];
    int total;
    int a;
    for(a=0; a<5; a++)
    {
        total += *ptr;
        printf("%d\n", total);
    }
    return 0;
}