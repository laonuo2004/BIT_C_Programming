#include <stdio.h>

int main()
{
	int n, t;
	scanf("%d", &n);
	int a[201308] = {0};
	for(int i = 1; i<=n; i++)
	{
		scanf("%d", &t);
		a[t]++;
	}
	int max = 0;
	for(int i = 0; i <=201307; i++)
	{
		if(a[i] != 0) max = i;
	}
	for(int i = 0; i <=201307; i++)
	{
		if(a[i] != 0 && i < max) printf("%d ", i);
	}
	printf("%d\n", max);
	return 0;
}