#include <stdio.h>

int main()
{
	int n,m,m1,std,k=0;
	scanf("%d%d",&n,&m);
	m1=m;
	std=n/m;
	while(n/m==std)
	{
		k++;
		m++;
	}
	while(n/m1==std)
	{
		k++;
		m1--;
	}
	k--;
	printf("%d\n",k);
	return 0;
}