#include <stdio.h>

int main()
{
	int n, counter = 1;
	scanf( "%d", &n);
	if( 0 == n) printf( "\n");
	else for( int i = 1; i <= n; i++)
		{
			for( int j = 1; j <= n; j++)
			{
				if( counter < 10) printf( "  %d", counter);
				else printf( " %d",counter);
				counter++;
			}
			printf( "\n");
		}
	return 0;
}