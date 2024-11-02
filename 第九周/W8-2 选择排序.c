#include <stdio.h>

int main()
{
	int n, min, k;
	scanf("%d", &n);
	int a[n+1];
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n-1; i++)
	{
		min = a[i];
		k = i;
		for(int j = i+1; j <=n; j++)
		{
			if(a[j]<min)
			{
				min = a[j];
				k = j;
			}
		}
		a[0] = a[i];
		a[i] = a[k];
		a[k] = a[0];
	}
	for(int i = 1; i <= n-1; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}