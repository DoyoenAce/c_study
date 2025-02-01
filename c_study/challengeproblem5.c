#include<stdio.h>
int main(void)
{
    int n =0;
    for(int i=0; i<10; i++)
    {
        n++;
        while(1)
        {
            int cnt=0;
            for(int x=1; x<=n; x++)
            {
                if (n%x == 0)
                {
                    cnt++;
                }
            }
            if(cnt==2)
            {
                printf("%d\n", n);
                break;
            }
            else
            {
                n++;
            }
            

        }
    }
}