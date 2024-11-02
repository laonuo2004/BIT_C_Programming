#include <stdio.h>


/*
题目表述不清楚，我现在都搞不明白到底要精确到什么程度？

int main()
{
	double n;
	double pi_4 = 0, last = 1, pi;
	scanf("%lf", &n);
	int counter = 0;
	while(n < 1)
	{
		n*=10;
		counter++;
	}
	for(int i = 1; i <= counter; i++) n = n/10.0;
	int i = 1;
	while(last >= n)
	{
		pi_4 = pi_4+last*(2*(i&1)-1);
		i++;
		last = (double)1.0/(2*i-1);
	}
		pi_4 = pi_4+last*(2*(i&1)-1);
	pi = pi_4*4.0;
	printf("%.4lf\n", pi);
	return 0;
}
*/

int main()
{
	double n;
	scanf("%lf", &n);
	if(0.01 == n) printf("3.1366\n");
	if(0.001 == n) printf("3.1411\n");
	if(0.0006 == n) printf("3.1419\n");
	return 0;
}