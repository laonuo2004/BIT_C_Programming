#include <stdio.h>

int main()
{
	int n, i = 1;
	scanf("%d", &n);
	while(n-i)
	{
		printf("%d ", i);
		i++;
	}
	printf("%d\n", n);
	return 0;
}