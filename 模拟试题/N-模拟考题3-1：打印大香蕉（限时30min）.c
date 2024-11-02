#include <stdio.h>
#include <math.h>

int main()
{
	long long n, x_1, r_1, x_2, r_2, table[250][250] = {0}, i, j, k;
	scanf("%ld%ld%ld%ld%ld", &n, &x_1, &r_1, &x_2, &r_2);
	for(i = 1; i <= 2*n+1; i++)
		for(j = 1; j <= 2*n+1; j++)
			if(j == n+1+x_1-r_1)
			{
				for(k = 1; k <= n; k++)
					table[k][j] = '.';
				table[k][j] = '*';
				for(k = n+2; k <= 2*n+1; k++)
					table[k][j] = '.';
			}
			else if((sqrt((i-n-1)*(i-n-1)+(j-x_1-n-1)*(j-x_1-n-1)) <= r_1) && (sqrt((i-n-1)*(i-n-1)+(j-x_2-n-1)*(j-x_2-n-1)) >= r_2) && j <= n+1+(x_1+x_2)/2)
				table[i][j] = '*';
			else
				table[i][j] = '.';
	for(i = 1; i <= 2*n+1; i++)
	{
		for(j = 1; j <= 2*n+1; j++)
			printf("%c", table[i][j]);
		printf("\n");
	}
	return 0;
}