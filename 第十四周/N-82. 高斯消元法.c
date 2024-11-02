#include <stdio.h>
#include <math.h>
#define maxn 100

 const double eps = 1e-8;
 void swap(void *a, void *b)
 {
 	double temp;
 	temp = *(double*)a;
 	*(double*)a = *(double*)b;
 	*(double*)b = temp;
 }
 
 int det(double A[maxn][maxn], int n, int exchange)
{
	double ans = 1;
	for(int i = 0; i < n; i++)
	{
		if(fabs(A[i][i]) < eps)
		{
			ans = 0;
			break;
		}
		ans *= A[i][i];
	}
	if(exchange&1 && fabs(ans)>eps)
		printf("%.2lf ", (-1)*ans);
	else
		printf("%.2lf ", ans);
	return 1;
}

int dimension(double A[maxn][maxn], int n, int count)
{
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int flag = 0;
		for(int j = 0; j < n; j++)
			if(fabs(A[i][j]) > eps)
			{
				flag = 1;
				break;
			}
		if(0 == flag)
			continue;
		ans++;
//		printf("%d\n", ans);
	}
	printf("%d %d\n", ans, n-ans);
	return 1;
}

 int guass_elimination(double A[maxn][maxn], int n) // 高斯消元
 {
     int i, j, k, r, count = 0, exchange = 0, flag = 0;
     for(i = 0; i < n; i++) { // 消元
         r = i;
         for(j = i + 1; j < n; j++) if(fabs(A[j][i]) > fabs(A[r][i])) r = j;
         if(fabs(A[r][i]) < eps)
         {
			flag = 0;
			for(j = i; j < n; j++)
				if(0 != A[r][j])
				{
					flag = 1;
					break;
				}
			if(flag)
         		count++;
         	continue;
		 }
         if(r != i)
		 {
			for(j = 0; j < n; j++)
				swap(&A[i][j], &A[r][j]); // 最大一行放最上面	
			exchange++;
		 }
         for(k = i + 1; k < n; k++) {
             double f = A[k][i] / A[i][i];
             for(j = i; j < n; j++) A[k][j] -= f * A[i][j]; // 成功消去第 i+1 列
         }
     }
//     for(i = 0; i < n; i++)
//	{
//		for(j = 0; j < n; j++)	
//     		printf("%5.2lf ", A[i][j]);
//     	printf("\n");
//	}
     det(A, n, exchange);
     dimension(A, n, count);
     return 1; 
 }

int main()
{
	int t, n;
	scanf("%d", &t);
	for(int i = 0; i < t; i++)
	{
		int n; double A[maxn][maxn] = {0};
		scanf("%d", &n);
		for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++)
				scanf("%lf", &A[j][k]);
		guass_elimination(A, n);
	}
	return 0;
}

//教训1：关于输出了-0.00？是因为那是浮点数，会存在误差，后面可能还有一些位数
//教训2：根本没有必要 count！最后高斯消元之后直接遍历即可
//教训3：浮点数是否为0？需要借助eps！
//教训4：同上，浮点数是否为0？要用到fabs！