#include<stdio.h>
int main(void)
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    int* ptr1 = &arr[0];
    int* ptr2 = &arr[5];
    int a;
    for(a=0; a<6; a++)
    {
        ptr1 -= 1;
        ptr2 += 1;
        printf("%d", arr[a]);
    }
    return 0;


}