#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,delta;
	double x0,x1,x2,s;
	scanf("%d%d%d",&a,&b,&c);
	if(0==a)
	{
		if(0==b)
		{
			printf("Input error!\n");
		}
		else
		{
			x0=(double)-c/b;
			printf("x=%.6lf\n",x0);
		}
	}
	else
	{
		delta=b*b-4*a*c;
		if(delta>0)
		{
			s=sqrt(delta);
			x1=(-b+s)/(2*a);
			x2=(-b-s)/(2*a);
			printf("x1=%.6lf\nx2=%.6lf\n",x1,x2);
		}
		else if(0==delta)
		{
			x0=(double)(-b)/(2*a);
			printf("x1=x2=%.6lf\n",x0);
		}
		else
		{
			if(0==b)
			{
				s=sqrt(-delta)/(2*a);
				printf("x1=%.6lfi\nx2=-%.6lfi\n",s,s);
			}
			else
			{
				s=sqrt(-delta)/(2*a);
				x0=(double)(-b)/(2*a);
				printf("x1=%.6lf+%.6lfi\nx2=%.6lf-%.6lfi\n",x0,s,x0,s);
			}
		}
	}
	return 0;
}