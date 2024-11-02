#include <stdio.h>

int main()
{
	int n,m,m1,std, k, k1=0, k2 = 0;
	int a[114514], b[114514];
	int i = 1, j = 1;
	scanf("%d%d",&n,&m);
	m1=m;
	std=n/m;
	while(n/m==std)
	{
		k1++;
		a[i] = m;
		i++;
		m++;
	}
	while(n/m1==std)
	{
		k2++;
		b[j] = m1;
		j++;
		m1--;
	}
	k = k1 + k2 - 1;
	printf("%d\n",k);
	for( int i = k2; i >= 2; i--) printf( "%d ", b[i]);
	for( int i = 1; i <= k1 - 1; i++) printf( "%d ", a[i]);
	printf( "%d\n", a[k1]);
	return 0;
}