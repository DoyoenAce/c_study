#include<stdio.h>
int main(void)
{
    int 초, h, min, sec;
    printf("초를 입력하세요.");
    scanf("%d", &초);
    sec = 초%60;
    h=초/3600;
    min=(초-3600*h)/60;
    printf("%d시간 %d분 %d초입니다.", h, min, sec);
    return 0;
}