#include <stdio.h>

int main()
{
	int n;
	int e, p;
	scanf("%d", &n);
	unsigned long long a[4002] = {0};
	for(int i = 1; i <=n; i++)
	{
		scanf("%d%d", &e, &p);
		if(0 == e)
		{
			int flag = 1;
			for(int j = 4000; j >=1; j--)
			{
				if(p < a[j])
				{
					flag = j+1;
					break;
				}
			}
			for(int j = 4000; j > flag; j--)
			{
				a[j] = a[j-1];
			}
			a[flag] = p;
		}
		else
		{
			int counter = 0, counter_0 = 0;
			for(int j = 4000; j >=1; j--)
			{
				counter_0++;
				if(a[j] != 0) counter++;
				if(counter == p)
				{
					printf("%d\n", a[4001 - counter_0]);
					for(int k = 4001 - counter_0; k <= 4000; k++)
					{
						a[k] = a[k+1];
					}
					break;
				}
			}
		}
	}
	return 0;
}