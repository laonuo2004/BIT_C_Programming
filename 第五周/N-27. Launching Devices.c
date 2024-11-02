#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, Ea, Eb, Va, Vb, Pa, Pb, P_collision1, P_collision2, P;
	scanf( "%lf%lf%lf%lf", &a, &b, &Ea, &Eb);
	Va = sqrt(2 * Ea / a);
	Vb = sqrt(2 * Eb / b);
	Pa = a * Va;
	Pb = b * Vb;
	P_collision1 = b * fabs( 2 * (Pa+Pb) / (a+b) - Vb);
	P_collision2 = b * fabs( 2 * (Pa-Pb) / (a+b) + Vb);
	P = fmax( P_collision1, Pb);
	P = fmax( P_collision2, P);
	printf( "%.2lf\n", P);
	return 0;
}