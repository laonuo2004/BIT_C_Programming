#include <stdio.h>

int main()
{
	double s, v;
	double p, q;
	scanf( "%lf%lf%lf", &s, &p, &q);
	v = (double) s * ( 0.1 + 0.9 * q / 100) * p / 100 + s * (1 - p / 100);
	printf( "%.2lf\n", v);
	return 0;
}