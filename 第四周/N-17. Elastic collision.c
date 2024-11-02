#include <stdio.h>
#include <math.h>

int main()
{
	double v, s, t, T;
	double x[4], m[7];
	v = s = t = T = x[0] = m[0] = 0;
	//scanf( "%lf%lf%lf", &v, &s, &t);
	scanf( "%lf%lf%lf%lf%lf%lf", &v, &x[1], &x[2], &x[3], &s, &t);
	for( int i = 1; i <= 3; i++)
	{
		m[i] = x[i] - s;
		m[i+3] = t - x[i];
	}
	for( int i = 1; i <= 6; i++) m[0] = fmax( m[0], m[i]);
	T = m[0]/v;
	printf( "%.1lf\n", T);
	return 0;
}