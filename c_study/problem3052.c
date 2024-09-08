#include<stdio.h>
int main(void)
{
    int a, b=0;
    int rest[10];

    for(int i=0; i<10; i++)
    {
        scanf("%d", &a);
        rest[i] = (a % 42);
    }
    for(int i =0; i<10; i++)
    {
        int cnt = 0;
        for(int j =i+1; j<10; j++)
        {
            if(rest[i] == rest[j]) cnt++;
        }
        if(cnt == 0) b++;
    }
    printf("%d", b);
    return 0;
}