#include <stdio.h>

int devide(int num, int *p)
{
	if(num/10)
	{
		*p = num%10;
		*p++;
		return 1+devide(num/10,p);
	}
	else
	{
		*p = num;
		return 1;
	}
}

int main()
{
	int n, cell, floor = 1, i, j, k, number[6] = {0}, *p, times, sum, temp, flag = 1;
	scanf("%d", &n);
	for(i = 1; i < n; i++)
		floor *= 10;
	cell = floor*10;
	for(i = floor; i < cell; i++)
	{
		for(j = 0; j <6; j++)
			number[j] = 0;
		p = number; sum = 0;
		times = devide(i, p);
		for(j = 0; j <6; j++)
		{
			temp = 1;
			for(k = 1; k <= times; k++)
				temp *= number[j];
			sum += temp;
		}
		if(sum == i)
		{
			printf("%d\n", i);
			flag = 0;
		}
	}
	if(flag)
		printf("No output.\n");
	return 0;
}