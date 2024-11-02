#include <stdio.h>

int main()
{
	int a, b, c, x;
	scanf( "%d%d%d", &a, &b, &c);
	x = a * b / 100;
	if( a< 400)
	{
		if( x > 400 - a) a = 400 + ( a + x - 400) * 0.8;
		else a+=x;
	}
	else
	{
		a = a + x * 0.8;
	}
	if( a< 400)
	{
		if( c > 400 -a) a = 400 + ( a + c - 400) * 0.8;
		else a+=c;
	}
	else
	{
		a = a + c * 0.8;
	}
	printf( "%d\n", a);
	return 0;
}