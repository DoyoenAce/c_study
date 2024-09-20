
#include <stdio.h>

int main(void) 
{
    double score;
    char subject[50];
    char major[2];

    double ans, sumScore, majorScore = 0.0;

    for (int i = 0; i < 20; i++){
        scanf("%s %lf %s", subject, &score, major);

        if (major[0] == 'P') {
            continue;
        } 
        sumScore += score;
        if (major[0] == 'F') {
            continue;
        }
        else if (major[0] == 'A') {
            majorScore = 4;
        }
        else if (major[0] == 'B') {
            majorScore = 3;
        }
        else if (major[0] == 'C') {
            majorScore = 2;
        }
        else {
            majorScore = 1;
        }
        if (major[1] == '+') {
            majorScore += 0.5;
        }
        ans += score * majorScore;
    }

    printf("%lf", ans / sumScore);

    return 0;
}