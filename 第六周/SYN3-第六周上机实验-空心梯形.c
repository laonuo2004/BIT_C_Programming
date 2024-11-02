#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if( 1 == n) printf("*\n");
	else
	{
		for(int i = 1; i <= 3*n - 2; i++) printf("*"); printf("\n");
		for(int i = 1; i <= n - 2; i++)
		{
			for(int j = 1; j <= i; j++) printf(" "); printf("*");
			for(int j = 1; j <= 3*n - 2*i - 4; j++) printf(" "); printf("*"); printf("\n");
		}
		for(int i = 1; i <= n - 1; i++) printf(" ");
		for(int i = 1; i <= n; i++) printf("*"); printf("\n");	
	}
	return 0;
}