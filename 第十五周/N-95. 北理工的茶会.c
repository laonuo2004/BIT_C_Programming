#include <stdio.h>

int main()
{
	int T, op, n, i, j, k;
	int number[1000], max = 0, d = 0, sum, sum_0;
	scanf("%d", &T);
	for(i = 1; i <= T; i++)
	{
		scanf("%d%d", &op, &n);
		if(op == 1)
		{
			max = 0; d = 0;
			for(j = 0; j < n; j++)
				scanf("%d", &number[j]);
			for(j = 0; j < n; j++)
			{
				sum = 0;
				for(k = 0; k < n; k++)
					if(number[(j+k)%n] == k) sum++;
				if(j == 0)
				{
					sum_0 = sum;
					max = sum_0;
				}
				else if(sum >= max && sum > sum_0)
				{
					d = j==0?0:n-j;
					max = sum;
				}
			}
			printf("%d %d\n", max, d);
		}
		else
			if(n&1) printf("1\n");
			else printf("2\n");	
	}
	return 0;
}