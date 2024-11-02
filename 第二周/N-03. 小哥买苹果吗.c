#include <stdio.h>

int main()
{
	int m,n,a,b,delta1,delta2,p,q;
	scanf("%d%d%d%d",&m,&n,&a,&b);
	delta1 = m - n*b;
	delta2 = a - b;
	p = delta1/delta2;
	q = n - p;
	printf("%d %d\n",p,q);
	return 0;
}