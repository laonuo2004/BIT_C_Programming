#include <stdio.h>

int main()
{
	int n, m;
	scanf( "%d%d", &n, &m);
	for( int i = n; i <= m; i++)
	{
		if( 0 == i % 3)
		{
			printf( "%d", i);
			break;
		}
	}
	printf("\n");
	return 0;
}