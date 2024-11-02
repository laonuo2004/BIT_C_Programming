#include <stdio.h>

int main()
{
	int n, position[100001] = {0}, science[100001] = {0}, i, j, k, flag = 1, time = 0, count;
	scanf("%d", &n);
	count = n;
	for(i = 1; i <= n; i++)
		scanf("%d", &position[i]);
	for(i = 1; i <= n; i++)
		scanf("%d", &science[i]);
	while(flag)
	{
		flag = 0;
		for(i = count; i >= 2; i--)
			if(science[i-1] > science[i])
			{
				flag = 1;
				break;
			}
		if(!flag)
			printf("%d\n", time);
		for(i = count; i >= 2; i--)
		{
			if(science[i-1]>science[i])
			{
				for(j = i; j < count; j++)
					science[j] = science[j+1];
				science[j] = -1;
				count--;
			}
		}
		time++;
	}
	return 0;
}