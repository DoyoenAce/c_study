#include<stdio.h>
int main(void)
{
    for(int i=1; i<=5; i++)
    {
        for(int a=1; a<=7; a++)
        {
            for(int b=1; b<=8; b++)
            {
                if(i*700+a*500+b*400==3500)
                {
                    printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", a,i,b);
                }
            }
        }
    }
    return 0;
}