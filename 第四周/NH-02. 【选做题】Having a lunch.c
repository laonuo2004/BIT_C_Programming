#include <stdio.h>

int one_distribute( int n)
{
	switch( n)
	{
		case 0: return 1; break;
		case 1: return 4; break;
		case 2: return 9; break;
		case 3: return 15; break;
		case 4: return 20; break;
		case 5: return 23; break;
		default: return 24;
	}
}

int main()
{
	long long int N1, N2, n1, n2, counter1 = 0, counter2 = 0;
	scanf( "%d%d", &N1, &N2);
	n1 = N1 / 3;
	n2 = N2 / 3;
	for( int i = 0; i <= n1; i++)
	{
		int n, j = 0;
		n = N1 - 3*i - 2*j;
		while( n >= 0)
		{
			counter1+=one_distribute( n);
			j++;
			n = N1 - 3*i - 2*j;
		}
	}
	for( int i = 0; i <= n2; i++)
	{
		int n, j = 0;
		n = N2 - 3*i - 2*j;
		while( n >= 0)
		{
			counter2+=one_distribute( n);
			j++;
			n = N2 - 3*i - 2*j;
		}
	}
	printf( "%d %d\n", counter1, counter2);
	return 0;
}