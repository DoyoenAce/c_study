#include<stdio.h>
int main(void)
{
    int n,k=0,g=1;
    printf("정수를 입력하세요:");
    scanf("%d", &n);
    while(1)
    {
       g *=2;
       if(g>n)
       {
            break;
            
       }
       k++;
    }
    printf("%d\n", k);

}