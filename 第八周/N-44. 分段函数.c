#include <stdio.h>
#include <math.h>

int main()
{
	double x, ans;
	scanf("%lf", &x);
	if(x < 0)
	{
		ans = pow(2, x)+1;
		printf("%.2lf\n", ans);
	}
	else if(x < 5)
	{
		ans = sqrt(x+4);
		printf("%.2lf\n", ans);
	}
	else if(x <= 16)
	{
		ans = 32.0/11.0-1.0/(x-16);
		printf("%.2lf\n", ans);
	}
	else printf("Jaanai tcl!\n");
	return 0;
}