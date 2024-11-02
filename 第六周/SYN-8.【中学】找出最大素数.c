#include <stdio.h>
#include <math.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i = 1; i <= n - 1; i++) a[i] = i;
	for(int i = 2; i <= sqrt(n)+1; i++)
	{
		for(int j = i*i; j <= n; j+=i) a[j] = 1;
	}
	for(int i = n - 1; i >=2; i--)
	{
		if(a[i] != 1)
		{
			printf("The max prime number is %d.\n", i);
			break;
		}
	}
	return 0;
}