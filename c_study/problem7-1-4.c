#include <stdio.h>

int main(void)
{
    int num;
    int i=9;

    printf("역순으로 출력할 단 입력:");
    scanf("%d", &num);

    while(i>0)
    {
        printf("%d x %d = %d \n", num, i, num*1);
        i--;
    }
    return 0;
}