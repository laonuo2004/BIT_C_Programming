#include <stdio.h>

int main()
{
	int n, table[1000][1000] = {0}, i, j, k;
	scanf("%d", &n);
	for(i = 1; i <= 2*n-1; i++)
		for(j = 1; j <= 2*n-1; j++)
			table[i][j] = '+';
	for(j = 2*n-1; j >= 1; j--)
	{
		table[1][j] = 'G';
		table[2*n-1][j] = 'G';
	}
	for(i = 1; i <= 2*n-1; i++)
		table[i][1] = 'G';
	for(i = n; i <= 2*n-1; i++)
		table[i][2*n-1] = 'G';
	for(j = n; j <= 2*n-1; j++)
		table[n][j] = 'G';
	for(i = 1; i <= 2*n-1; i++)
	{
		for(j = 1; j <= 2*n-1; j++)
			printf("%c", table[i][j]);
		printf("\n");
	}
	return 0;
}