#include <stdio.h>
#include <math.h>

double plus(double *a, double *b, int d)
{
	double sum = 0;
	for(int i = 1; i <= d; i++)
	{
		sum += (*a)*(*b);
		*a++; *b++;
	}
	return sum;
}

void ort(double *a, double *b, int d, double *c)
{
	double p_1 = plus(a, b, d);
	double p_2 = plus(b, b, d);
	for(int i = 1; i <= d; i++)
	{
		*c = (*b)*(p_1/p_2);
		*b++; *c++; 
	}
}

int main()
{
	int n, d;
	scanf("%d%d", &n, &d);
	double a[11][11] = {0}, b[11][11] = {0}, c[11] = {0};
	double p;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= d; j++)
		{
			scanf("%lf", &a[i][j]);
			b[i][j] = a[i][j];
		}
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= i-1; j++)
		{
			ort(&a[i][1], &b[j][1], d, &c[1]);
			for(int k = 1; k <= d; k++)
			{
				b[i][k] -= c[k];
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		p = 0;
		for(int j = 1; j <= d; j++)
		{
			p += pow(b[i][j], 2);
		}
		p = sqrt(p);
		for(int j = 1; j <= d; j++)
		{
			b[i][j] /= p;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		int j = 1;
		for(; j <= d-1; j++)
		{
			printf("%.2lf ", b[i][j]);
		}
		printf("%.2lf\n", b[i][j]);
	}
	return 0;
}

//教训1：传入数组元素的地址作为指针的时候，由于个人习惯，要传入 &a[i-1][1] 或者 c[1]；
//教训2： /= %= ……还有很多类似的运算符都是可行的！