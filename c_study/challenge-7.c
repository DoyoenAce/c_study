#include<stdio.h>
int main(void)
{
    int n, k=0, a=1;
    printf("정수를 입력해 주세요:");
    scanf("%d", &n);
    while(1)
    {
        a *=2; // *=는 복합 대입 연산자
        if(a>n)
        {
            break;
        }
        k++;
    }
    printf("%d", k);
    return 0;
}