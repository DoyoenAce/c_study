#include <stdio.h>

int main(void)
{
	int a;
	int b = 0;
	int c = 0;

	for (int i = 1; i < 10; ++i)
    {
		scanf("%d", &a);
		if (a > b) {
			b = a;
			c = i;
		}
	}
    
	printf("%d\n%d\n", b , c);
	return 0;
}