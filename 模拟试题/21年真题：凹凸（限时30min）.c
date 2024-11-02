#include <stdio.h>

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	if(n&1)
	{
		for(i = 1; i <= n/2-1; ++i)
			printf(" ");
		for(i = 1; i <= n/2+2; ++i)
			printf("*");
		printf("\n");
		for(j = 1; j <= n/3; ++j)
		{
			for(i = 1; i <= n/2-1; ++i)
				printf(" ");
			printf("*");
			for(i = 1; i <= n/2; ++i)
				printf(" ");
			printf("*\n");
		}
		for(i = 1; i <= n/2; ++i)
			printf("*");
		for(i = 1; i <= n/2; ++i)
			printf(" ");
		for(i = 1; i <= n/2-1; ++i)
			printf("*");
		printf("*\n");
		for(j = 1; j <= n/2-1; ++j)
		{
			printf("*");
			for(i = 1; i <= (n/2)*3-2; ++i)
				printf(" ");
			printf("*\n");
		}
		for(i = 1; i <= (n/2*3); ++i)
			printf("*");
		printf("\n");
	}
	else
	{
		for(i = 1; i <= n/2; ++i)
			printf("*");
		for(i = 1; i <= n/2-1; ++i)
			printf(" ");
		for(i = 1; i <= n/2-1; ++i)
			printf("*");
		printf("*\n");
		for(j = 1; j <= n/3; ++j)
		{
			printf("*");
			for(i = 1; i <= n/2-2; ++i)
				printf(" ");
			printf("*");
			for(i = 1; i <= n/2-1; ++i)
				printf(" ");
			printf("*");
			for(i = 1; i <= n/2-2; ++i)
				printf(" ");
			printf("*\n");
		}
		printf("*");
		for(i = 1; i <= n/2-2; ++i)
			printf(" ");
		for(i = 1; i <= n/2+1; ++i)
			printf("*");
		for(i = 1; i <= n/2-2; ++i)
			printf(" ");
		printf("*\n");	
		for(j = 1; j <= n/2-1; ++j)
		{
			printf("*");
			for(i = 1; i <= (n/2)*3-3; ++i)
				printf(" ");
			printf("*\n");
		}		
		for(i = 1; i <= (n/2)*3-1; ++i)
			printf("*");
		printf("\n");
	}
	return 0;
}