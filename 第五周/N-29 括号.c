#include <stdio.h>

int main()
{
	int n, flag = 1, counter1 = 0, counter2 = 0;
	scanf( "%d", &n);
	getchar();
	if( n%2 != 0)
	{
		flag = 0;
	}
	else
	{
		int s[n+1];
		for( int i = 1; i <= n; i++)
		{
//			scanf( "%d", &s[i]);
			s[i] = getchar();
			if( 91 == s[i]) counter1++;
			else counter2++;
			if( counter2 > counter1)
			{
				flag = 0;
				break;
			}
		}
		if( counter1 != counter2) flag = 0;
	}
	if( 1 == flag) printf( "Yes\n");
	else printf( "No\n");
	return 0;
}