#include <stdio.h>
#include <math.h>

int main()
{
	double m,r,v;
	double g=6.67e-11;
	scanf("%lf%lf",&m,&r);
	v=sqrt(g*m/r);
	printf("%e\n",v);
	return 0;
}