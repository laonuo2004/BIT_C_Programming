#include <stdio.h>

int main()
{
	int n, m, sum = 0;
	scanf( "%d%d", &n, &m);
	for( int i = n; i <= m; i++)
	{
		if( 0 == i % 3)
		{
			printf( "%d\n", i);
			sum++;
		}
	}
	if( 0 == sum) printf("\n");
	return 0;
}