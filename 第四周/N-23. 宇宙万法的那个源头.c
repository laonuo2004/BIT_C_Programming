#include <stdio.h>

int exor( int n)
{
	int k;
	k = n % 4;
	switch( k)
	{
		case 1: return 1; break;
		case 2: return n + 1; break;
		case 3: return 0; break;
		default: return n;
	}
}

int main()
{
	int n, l, r;
	scanf( "%d", &n);
	for( int i = 1; i <= n; i++)
	{
		scanf( "%d%d", &l, &r);
		printf( "%d\n", exor( l-1) ^ exor( r));
	}
	return 0;
}