#include <stdio.h>

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	int table[100][100] = {0};
	for(i = 0; i < n; i++)
		table[i][0] = 1;
	for(j = 1; j < n; j++)
		table[i-1][j] = 1;
	for(i = 0; i < n; i++)
	{
		table[i][n+1] = 1;
		table[0][i+n+1] = 1;
	}
	for(j = 1; j < n; j++)
	{
		table[i-1][j+n+1] = 1;
		table[j][i+n] = 1;
	}
	for(i = 0; i < n; i++)
		table[i][2*n+2] = 1;
	for(j = 1; j < n; j++)
		table[i-1][j+2*n+2] = 1;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j <= 3*n+1; j++)
			if(table[i][j])
				printf("*");
			else if(j <= 2*n+2)
				printf(" ");
		printf("\n");
	}
//	for(k = 0; k <= 3*n+1;k++)
//		printf("%d", table[0][k]);
	return 0;
}

//教训1：事实证明：使用二维表格打印图形拥有很强的灵活性，不过自己要分得清楚行和列！