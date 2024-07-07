#include <stdio.h>

int main(void)
{
    int i;
    double num = 0.0;

    for(i=0; i<1000000; i++)
        num+=0.001;
    printf("o.00001을 1000번 더한 결과: %lf \n", num);
    return 0;
}