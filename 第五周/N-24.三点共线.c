#include <stdio.h>

int main()
{
	int a[7], s = 1;
	for( int i = 1; i <= 15; i++)
	{
		a[s] = getchar();
		if( a[s] != 40 && a[s] != 41 && a[s] != 44)
		{
			s++;
		}
	}
	int x1, x2, y1, y2;
	x1 = a[3] - a[1];
	y1 = a[4] - a[2];
	x2 = a[5] - a[1];
	y2 = a[6] - a[2];
	if(x1*y2 == x2*y1) printf( "Yes\n");
	else printf( "No\n");
	return 0;
}