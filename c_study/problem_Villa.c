#include<stdio.h>
int main(void)
{
    int villa[4][6];
    int popu, i, j;
    for(i=0; i<4; i++)
    {
        for(j = 0; j<6; j++)
        {
            printf("%d층 %d호 인구수: ", i+1, j+1);
            scanf("%d", &villa[i][j]);
        }
    }
    for(i=0; i<4; i++)
    {
        popu = 0;
        popu += villa[i][0];
        popu += villa[i][1];
        popu += villa[i][2];
        popu += villa[i][3];
        popu += villa[i][4];
        popu += villa[i][5];
        printf("%d층 인구수: %d \n", i+1, popu);
    }
    return 0;
}