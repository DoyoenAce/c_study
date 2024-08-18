#include <stdio.h>

int main(void) 
{
	int a;
	scanf("%d", &a);

	int b,c ;
	for (int i = 1; i <= a; ++i) 
    {
		scanf("%d %d", &b, &c);
		printf("Case #%d: %d\n", i, b+c);
	}
	return 0;
}