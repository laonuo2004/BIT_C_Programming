#include <stdio.h>

int main()
{
	int n, m, t, s = 0;
	scanf( "%d%d%d", &n, &m, &t);
	int a[m+1];
	for( int i = 1; i <= m; i++) scanf( "%d", &a[i]);
	for( int i = 1; i <= m; i++)
	{
		if( a[i] < t) s+=( t - a[i]);
	}
	if( n >= s) printf( "Y\n%d\n", n - s);
	else printf( "N\n%d\n", s - n);
	return 0; 
}