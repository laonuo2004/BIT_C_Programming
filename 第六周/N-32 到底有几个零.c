#include <stdio.h>

unsigned long long zero(unsigned long long n)
{
	unsigned long long counter = 0;
	if(0 == n/5) return counter;
	else
	{
		counter+=(n/5 + zero(n/5));
		return counter;
	}
}

int main()
{
	int m;
	scanf("%d", &m);
	unsigned long long a[m+1];
	for(int i = 1; i <= m; i++)
	{
		scanf("%llu", &a[i]);
		printf("%llu\n", zero(a[i]));
	}
	return 0;
}