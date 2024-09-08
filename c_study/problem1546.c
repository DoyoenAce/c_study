#include<stdio.h>
int main(void)
{
    int a, score;
    scanf("%d", &a);

    int max = 0;
    int total = 0;
    for(int i = 0; i < a ; i++)
    {
        scanf("%d", &score);
        total += score;
        if (score > max)
        {
            max = score;
        }
    }
    printf("%f\n", 100.0 * total / a /max);
    return 0;
}