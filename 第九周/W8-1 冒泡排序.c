#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1];
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n-1; i++)
	{
		for(int j = 1; j <= n-i;j++)
		{
			if(a[j] > a[j+1])
			{
				a[0] = a[j];
				a[j] = a[j+1];
				a[j+1] = a[0];
			}
		}
	}
	for(int i = 1; i <= n-1; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}