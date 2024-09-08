#include<stdio.h>
int main(void)
{
    int student[31] = {0}; // 인덱스 0부터 시작
    int num;

    for(int i = 0; i< 28 ; i++)
    {
        scanf("%d", &num);
        student[num] = num;
    }
    for(int i = 1; i<31; i++)
    {
        if(student[i] == 0)
        {
            printf("\n%d", i);
        }
    }
    return 0;
}