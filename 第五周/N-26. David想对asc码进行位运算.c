#include <stdio.h>

int main()
{
	int a, b, a_copy, b_copy, former, latter, result;
	scanf( "%c%c", &a, &b);
	a_copy = a;
	b_copy = b;
	a_copy>>=4;
	b_copy>>=4;
	a_copy<<=4;
	b_copy<<=4;
	a = a - a_copy;
	b = b - b_copy;
	latter = a^b;
	former = a_copy&b_copy;
	result = latter + former;
	printf( "%c\n", result);
	return 0;
}