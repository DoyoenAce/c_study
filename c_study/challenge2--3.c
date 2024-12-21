#include <stdio.h>
int main(void) {
   int arr[10];
   int n, odd_count = 0, even_count = 0;


   for (int i = 0; i < 10; i++) {
       printf("입력:");
       scanf("%d", &n);
       if (n % 2 == 1) {
           arr[odd_count++] = n;
       }
       else {
           arr[(9 - (even_count++))] = n;
       }
   }

   for (int i = 0; i < 10; i++) {
       printf("%d ", arr[i]);
   }
}

