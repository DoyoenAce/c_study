#include <stdio.h>
int main(void){
    int N,i=0;
    char num[30];

    scanf("%d", &N);

    while(N>0){
        num[i++]=N%2;
        N/=2;
    }
    while(i>0){
       i--;
       printf("%d ", num[i]);
    }
   return 0;
}