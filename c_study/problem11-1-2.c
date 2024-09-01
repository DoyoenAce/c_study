#include<stdio.h>
int main(void)
{
    char str[] = {'G','o','o','d',' ','T','i','m','e'};
    int arr = sizeof(str)/sizeof(char);
    for(int i = 0; i<arr; i++)
    {
        printf("%c \n", str[i]);
    }
    return 0;
    
}