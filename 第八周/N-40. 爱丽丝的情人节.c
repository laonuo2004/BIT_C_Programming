#include <stdio.h>

int main()
{
	int a[4], b[4], c[4], v;
	for(int i = 1; i <= 3; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= 3; i++) scanf("%d", &b[i]);
	for(int i = 1; i <= 3; i++) c[i] = a[i]/b[i];
	v = b[1]*c[1]*b[2]*c[2]*b[3]*c[3];
	double percent;
	percent = (double)v*100/(a[1]*a[2]*a[3]);
//	percent = (double)((((a[1]/b[1])*b[1])*((a[2]/b[2])*b[2])*((a[3]/b[3])*b[3]))*100)/(a[1]*a[2]*a[3]);
	printf("%.2lf%%\n", percent);
	return 0;
}