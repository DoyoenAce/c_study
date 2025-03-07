#include<stdio.h>
int main(void)
{
    for(int i=1; i<= 5; i++)
    {
        for(int j = 1; j <= 7; j++)
        {
            for(int k = 1; k <= 8; k++)
            {
                if(i*700+j*500+k*400 == 3500)
                {
                    printf("크림빵 %d개, 새우깡 %d개, 콜라 %d개\n", i, j, k);

                }
            }
        }
    }
    printf("어떻게 구입하시겠습니까?\n");
    return 0;
}