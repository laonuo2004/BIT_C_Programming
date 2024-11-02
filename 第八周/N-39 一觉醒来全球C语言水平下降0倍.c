#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n+1], b[n+1];
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= n-1; i++) printf("%d ", a[i]+b[i]);
	printf("%d\n", a[n]+b[n]);
	return 0;
}