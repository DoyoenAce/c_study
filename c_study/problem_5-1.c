#include<stdio.h>
int main(void)
{
    int xposition1, yposition1;
    int xposition2, yposition2;
    int area;

    printf("왼쪽 위의 x,y 좌표:");
    scanf("%d %d", &xposition1, &yposition1);
    printf("오른쪽 위의 x,y좌표:");
    scanf("%d %d", &xposition2, &yposition2);
    area = (xposition2-xposition1)*(yposition2-yposition1);
    printf("두 점이 이루는 사각형의 넓이는 %d입니다. \n", area);
    return 0; 
}