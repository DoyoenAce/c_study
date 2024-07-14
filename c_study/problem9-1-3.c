#include <stdio.h>
void Fibo (int num)
{
    int fibo1=0, fibo2=1 fibo3, i;
    if (num==1)
    {
        printf("%d", fibo1);
    }
    else
    {
        printf("%d %d", fibo1, fibo2);
    }
    for(i=0; i<num-2; i++);
    {
        fibo3=fibo1+fibo2; //피보나치 규칙
        printf("%d", fibo3);
        fibo1 = fibo2;
        fibo2=fibo3;
    }
}

    int main(void)
    {
        int n;
        printf("출력하고 싶은 피보나치 수열의 갯수:");
        scanf("%d", &n);
        if(n<1)
        {
            printf("1 이상의 값을 입력하세요:");
            return -1
        }
        Fibo(n);
        return 0;
    }
