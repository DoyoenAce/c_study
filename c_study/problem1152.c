#include<stdio.h>
#include<string.h>
int main(void)
{
    int cnt = 0;
    char a[1000001];
    scanf("%[^\n]", a);
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i] == 32)
        {
            cnt++;
        } 
    }
    if(a[0] == 32)
    {
        cnt--;
    }
    if(a[strlen(a)-1] == 32)
    {
        cnt--;
    }
    printf("%d", cnt+1);
}