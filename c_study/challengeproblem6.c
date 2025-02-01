#include<stdio.h>
int main(void)
{
    int hour, min, sec, cho;
    printf("초를 입력해 주세요.");
    scanf("%d", &cho);
    sec = cho%60;
    hour = cho/3600;
    min = (cho-hour*3600)/60;
    printf("%d시간 %d분 %d초 입니다.", hour, min, sec);
    return 0;
}