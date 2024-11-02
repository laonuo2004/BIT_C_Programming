#include <stdio.h>

int main()
{
	int n, bl = 0;
	scanf( "%d", &n);
	int a[n+1];
	for( int i = 0; i <= n; i++) a[i] = getchar();
	/*for( int i = 1; i <= n; i++)
		if (115 == a[i])
			for( int j = i + 1; j <= n; j++)
				if (116 == a[j])
				{
					bl = 1;
					goto p;
				}
	p: if( 1 == bl) printf( "good pronunciation\n");
	else printf( "just like Eijvy\n");*/
	int p = n + 1, q = 0;
	for( int i = 1; i <= n; i++)
	{
		if( 115 == a[i])
		{
			p = i;
			break;
		}
	}
	for( int j = n; j >= 1; j--)
	{
		if( 116 == a[j])
		{
			q = j;
			break;
		}
	}
	if( p < q) printf( "good pronunciation\n");
	else printf( "just like Eijvy\n");
	return 0;
}