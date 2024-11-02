#include <stdio.h>

long long cumulate[2001][2001] = {0};

long long max(long long a, long long b)
{
	if(a > b) return a;
	else return b;
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= i; j++)
		{
			scanf("%lld", &cumulate[i][j]);
			cumulate[i][j] += max(cumulate[i-1][j-1], cumulate[i-1][j]);
		}
//	for(i = 1; i <= n; i++)
//	{
//		for(j = 1; j <= i; j++)
//		{
//			scanf("%lld", &cumulate[i][j]);
//			cumulate[i][j] += max(cumulate[i-1][j-1], cumulate[i-1][j]);
//			printf("%lld ", cumulate[i][j]);
//		}
//		printf("\n");
//	}
	long long m = cumulate[n][1];
	for(i = 2; i < n; i++)
		m = max(cumulate[n][i], m);
	printf("%lld\n", m);
	return 0;
}