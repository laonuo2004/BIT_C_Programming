#include <stdio.h>

int main()
{
	int h, d, i, j, k, count;
	scanf("%d%d", &h, &d);
	for(i = 1; i <= h; i++)
	{
		count = 1;
		for(j = 1; j <= i-1; j++)
		{
			printf(" ");
			count++;
		}
		for(j = 1; j <= d && j <= 2*h-2*i+1; j++)
		{
			printf("*");
			count++;
		}
		for(j = 1; j <= 2*h-2*i+1-2*d; j++)
		{
			printf(" ");
			count++;
		}
		for(j = count; j <= 2*h-i; j++)
			printf("*");
		printf("\n");
	}
	return 0;
}