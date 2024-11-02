#include <stdio.h>
#include <math.h>

int gcd(int num1,int num2);

int main()
{
	int k,a,b,m,n,p,q = 0;
	scanf("%d%d%d",&k,&a,&b);
	if (k == 1)
	{
		m = 2;
	}
	else
	{
		m = 3;
	}
	n = abs(720/a) % 10;
	p = gcd(1234,4321);
	q = ((463*b)/gcd(463,b))/10 % 10;
	printf("%d%d%d%d\n",m,n,p,q);
	return 0;
}

int gcd(int num1,int num2)
{
	if (num1 % num2 ==0)
	{
		return num2;
	}
	else
	{
		return gcd(num2,num1 % num2);
	}
}