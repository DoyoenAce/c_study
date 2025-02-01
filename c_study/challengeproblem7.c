#include<stdio.h>
int main(void)
{
    int n;
    int k=0;
    int a=1;
    printf("숫자 n을 입력해 주세요:");
    scanf("%d", &n);
    while(1)
    {
        a *=2;
       if(a>n)
       {
            break;    
       }
       k++;
    }
    printf("%d\n", k);
    return 0;
}