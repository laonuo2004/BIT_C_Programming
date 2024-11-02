#include <stdio.h>

int main()
{
	int n, a[10000] = {0}, i, j, k;
	for(i = 2; i <= 100; i++)
		for(j = i*i; j <= 10000; j+=i)
			a[j] = 1;
	scanf("%d", &n);
	while(n)
	{
		if(!a[n])
		{
			printf("The max prime number is %d.\n", n);
			break;
		}
		n--;
	}
	return 0;
}