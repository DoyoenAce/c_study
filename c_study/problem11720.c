#include<stdio.h>
int main(void)
{
    int input;
    int sum;
    char arr[100] = " ";

    scanf("%d", &input);
    scanf("%s", arr);

    for(int i = 0; i<input; i++)
    {
        sum += arr[i]-'0';
    }
    printf("%d", sum);
    return 0;
}