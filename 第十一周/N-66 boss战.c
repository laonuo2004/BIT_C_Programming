#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[10001] = {0};
	a[0] = 1; a[1] = 1;
	for(int i = 2; i <= 100; i++)
	{
		for(int j = i*i; j <= 10000; j+=i)
		{
			a[j] = 1;
		}
	}
	for(int i = 1; i <= n-2; i++)
	{
		if(a[i] == 0 && a[i+1] == 0) printf("%d\n", i*(i+1));
		if(a[i] == 0 && a[i+2] == 0) printf("%d\n", i*(i+2));
	}
	return 0;
}