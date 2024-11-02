#include <stdio.h>

int main()
{
	int n, min, k;
	scanf("%d", &n);
	int a[n+1];
	scanf("%d", &a[1]);
	for(int i = 1; i <= n-1; i++)
	{
		scanf("%d", &a[0]);
		int j = i;
		for(j; j >= 1; j--)
		{
			if(a[0]<a[j]) a[j+1]=a[j];
			else break;
		}
		a[j+1] = a[0];
	}
	for(int i = 1; i <= n-1; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}