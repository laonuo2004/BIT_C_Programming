#include <stdio.h>

int prime( int n)
{
	int flag = 1;
	for( int i = 2; i <= n-2; i++)
	{
		if( 0 == n%i)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{
	int n;
	scanf( "%d", &n);
	for( int i = 2; i <= n-2; i++)
	{
		if( 1 == prime(i) && 1 == prime(n - i))
		{
			printf( "%d=%d+%d\n", n, i, n - i);
			break;
		} 
	}
	return 0;
}