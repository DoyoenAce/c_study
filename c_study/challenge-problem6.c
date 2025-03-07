#include<stdio.h>
int main(void)
{
    int cho, hour, min, sec;
    printf("give me the seconds you want:");
    scanf("%d", &cho);
    sec = cho%60;
    hour = cho/3600;
    min = (cho-3600*hour)/60;
    printf("It's %d hours, %d minutes, and %d seconds\n", hour, min, sec);
    return 0;
}