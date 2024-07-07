#include <stdio.h>

double CelToFah(double c)
{
    return 1.8*c+32;
}
double FahToCel(double f)
{
    return (f-32)/1.8;
}
int main (void)
{
    int cel;
    double num;
    printf("1.섭씨를 화씨로 변환2.화씨를 섭씨로 변환\n");
    printf("선택->");
    scanf("%d", &cel);

    if (cel == 1)
    {
        printf("섭씨 입력");
        scanf("%lf",&num);
        printf("변환된 결과: %f \n", CelToFah(num));

    }
    else if (cel==2)
    {
        printf("화씨 입력:");
        scanf("%lf", &num);
        printf("변환된 결과: %f \n" , FahToCel(num));

    }
    else
    {
        printf("선택을 잘못하셨습니다.\n");
        
    }
    return 0;
}