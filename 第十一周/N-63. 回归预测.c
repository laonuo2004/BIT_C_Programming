#include <stdio.h>
#include <math.h>

double mean(int a[], int n)
{
	double sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum = sum + a[i];
	}
	return sum/n;
}

double mean_(int a[], int b[], double a_, double b_, int n)
{
	double sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum = sum + (a[i]-a_)*(b[i]-b_);
	}
	return sum;
}

int main()
{
	int n, p;
	int x[50001] = {0}, y[50001] = {0};
	double x_, y_, b, a, predict;
	while(scanf("%d", &n) != EOF)
	{
		scanf("%d", &p);
		for(int i = 1; i <= n; i++) scanf("%d", &x[i]);
		for(int i = 1; i <= n; i++) scanf("%d", &y[i]);
		x_ = mean(x, n); y_ = mean(y, n);
		b = mean_(x, y, x_, y_, n)/mean_(x, x, x_, x_, n);
		a = y_-b*x_;
		predict = b*p+a;
		if(fabs(a) < 0.005) printf("y=%.2fx predict=%.2f\n", b, predict);
		else if(fabs(b) < 0.005) printf("y=%.2f predict=%.2f\n", a, predict);
		else if(a>0) printf("y=%.2fx+%.2f predict=%.2f\n", b, a, predict);
		else printf("y=%.2fx%.2f predict=%.2f\n", b, a, predict);
	}
	return 0;
}

//教训1：向函数传入数组时，不需要加方括号！ e.g. x_ = mean(x, n)✔， x_ = mean(x[50001], n)✖；
//教训2：在主函数定义的变量，在自定义函数里是无法使用的！只能通过形参传进去。
//教训3：不要直接让浮点数与一个数相等！
//教训4：注意好输出格式！当a为负值时，应当输出负号，而原先的 printf("y=%.2fx+%.2f predict=%.2f\n", b, a, predict) 使得a前既有正号也有负号；