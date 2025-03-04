#include<stdio.h>
int main(void)
{
    int a=0;
    for(int i=0; i<10; i++)
    {
        a++;
        while(1)
        {
            int cnt=0;
            for(int x=1; x<=a; x++)
            {
                if (a%x == 0)
                {
                    cnt++;
                }
            }
            if(cnt==2)
            {
                printf("%d", a);
                break;
            }
            else
            {
                a++;
            }
            

        }
    }
}