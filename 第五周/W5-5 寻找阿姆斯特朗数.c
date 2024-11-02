#include <stdio.h>

int main()
{
	int n, bottom = 1, top, flag = 0;
	scanf( "%d", &n);
	int a[n+1];
	for( int i = 1; i < n; i++)
	{
		bottom*=10;
	}
	top = bottom * 10 - 1;
	int k = bottom;
	for( ; k <= top; k++)
	{
		int counter = 0, sum = 0, k_copy = k;
		while( k_copy != 0)
		{
			counter++;
			a[counter] = k_copy % 10;
			k_copy = k_copy / 10;
		}
		for( int i = 1; i <= n; i++)
		{
			int check = 1;
			for( int j = 1; j <= counter; j++) check*=a[i];
			sum+=check;
		}
		if( k == sum)
		{
			printf( "%d\n", k);
			flag = 1;
		}
	}
	if( 0 == flag) printf( "No output.\n");
	return 0;
}