#include <stdio.h>
#include <math.h>
#define eps 0.00001

int main()
{
	int n, i, j, k, flag = 0;
	double sum;
	scanf("%d%lf", &n, &sum);
	for(i = n; i >= 0; i--)
		for(j = n-i; j >= 0; j--)
			if(fabs(12*i+3.4*j+2.3*(n-i-j)-sum) < eps)
			{
				printf("%d %d %d\n", i, j, n-i-j);
				flag = 1;
			}
	if(!flag)
		printf("Error!\n");
	return 0;
}

//教训1：浮点数相等的时候要记得加fabs()！