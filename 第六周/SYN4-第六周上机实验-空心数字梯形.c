#include <stdio.h>

int main()
{
	int n, h;
	scanf("%d%d", &n, &h);
	if( 1 == n) printf("%d\n", h);
	else
	{
		for(int i = 1; i <= 3*n - 2; i++) printf("%d", h%10); printf("\n");
		for(int i = 1; i <= n - 2; i++)
		{
			for(int j = 1; j <= i; j++) printf(" "); printf("%d", (h+i)%10);
			for(int j = 1; j <= 3*n - 2*i - 4; j++) printf(" "); printf("%d", (h+i)%10); printf("\n");
		}
		for(int i = 1; i <= n - 1; i++) printf(" ");
		for(int i = 1; i <= n; i++) printf("%d", (n+h-1)%10); printf("\n");	
	}
	return 0;
}