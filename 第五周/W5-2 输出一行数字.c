#include <stdio.h>

int main()
{
	int m, n;
	scanf( "%d%d", &m, &n);
	for( int i = 0; i <n; i++) printf( "%d", m+i);
	printf( "\n");
	return 0;
}