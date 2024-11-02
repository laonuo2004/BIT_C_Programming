#include <stdio.h>

int main()
{
	int n;
	unsigned long long s, p[5001] = {0}, c[5001] = {0};
	scanf("%d%llu", &n, &s);
	for(int i = 1; i <= n; i++)
	{
		scanf("%llu", &p[i]);
	}
	for(int i = 1; i <= n; i++)
	{
		scanf("%llu", &c[i]);
	}	
	unsigned long long max = c[1], sum = 0, option = 0;
	for(int i = 2; i <= n; i++)
	{
		if(max < c[i]) max = c[i];
	}
	for(int i = 1; i <= max; i++)
	{
		option = 0;
		for(int j = 1; j <= n; j++)
		{
			if(c[j] > 0)
			{
				option = option + p[j];
				c[j]--;
			}
		}
		if(s < option)
		{
			sum = sum + s;
		}
		else
		{
			for(int j = 1; j <= n; j++)
			{
				option = option + p[j]*c[j];
			}
			sum = sum + option;
			break;
		}
	}
	printf("%d", sum);
	return 0;
}