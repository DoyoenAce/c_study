#include<stdio.h>
int main(void)
{
    int n,m;
    int i,j;
    int k;
    int arr[101] = { 0, };
    scanf("%d %d", &n, &m);
    for(k = 1; k <= n; k++)
    {
        arr[k] = k;
    }
    for(k = 0; k < m; k++)
    {
        scanf("%d %d", &i, &j);
        while(i <= j)
        {
            int basket = 0;
            basket = arr[i];
            arr[i] = arr[j];
            arr[j] = basket;
            i += 1;
            j -= 1;
        }
    }
    for(k = 1; k <= n; k++)
    {
        printf("%d ", arr[k]);
    }
    return 0;
}