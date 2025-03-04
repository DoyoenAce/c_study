#include<stdio.h>
int square_by_value(int num)
{
    return num*num;
}
void square_by_refernce(int * n)
{
    int num = *n;
    *n = num*(num);

    //return *n;
}
int main(void)
{
    int num = 7;
    printf("%d\n", square_by_value(num));
    square_by_refernce(&num);
    printf("%d \n", num);
    return 0;
}