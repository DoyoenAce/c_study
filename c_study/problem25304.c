#include <stdio.h>
 
int main(void){
    int X, N;
    scanf("%d\n %d", &X, &N);
    
    int sum = 0;
    for(int i=0; i<N; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sum += a*b;
    }
 
    if(X == sum){
        printf("Yes");
    }
    else{
        printf("No");
    }
 
    return 0;
}
