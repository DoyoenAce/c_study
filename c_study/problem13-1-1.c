#include<stdio.h>
int main(void)
{
    int arr[5] = {1, 2, 3, 4, 5};
    int ptr = arr[1];
    int a;
    for(a=0; a<5; a++)
    {
        ptr += 2;
        ptr++;
    }
    printf("%d\n", arr[a]);
    return 0;

}