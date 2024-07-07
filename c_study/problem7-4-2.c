#include <stdio.h>
int main(void)
{
    int num, i;
    int result=1;

    printf("정수를 입력하세요; ");
    scanf("%d", &num);

    for(i = 1; i<=num ; i++)
    {
        result = result*i;

    printf("%d!= %d \n", num, result);
    }    
    return 0;
}

