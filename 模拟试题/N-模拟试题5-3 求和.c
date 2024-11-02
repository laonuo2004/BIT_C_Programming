#include <stdio.h>

double recursion(int n)
{
	if(n)
		return recursion(n-1)+1/((double)n*2-1);
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%lf\n", recursion(n));
	return 0;
}