#include <stdio.h>
const int mod = 167772161; //定义求余用的常数

int main()
{
	int n, t, counter = 0;
	unsigned long long ans = 1; //防止ans过大，所以定义得大一些
	scanf("%d", &n);
	int a[n+1];
	for(int i = 1; i <= n; i++) a[i] = 0; //初始化数组
 	for(int i = 1; i <= n; i++) //这一循环使用桶排序，实际上就是统计成绩范围 "1到N" 每一个值分别有多少个Ai与之对应
	{
		scanf("%d", &t);
		a[t]++;
	}
	for(int i = 1; i <= n; i++) //i从1到N，遍历成绩范围中的每一个值
	{
		for(int j = 1; j <= a[i]; j++) //j从1到a[i]，表示对于一个成绩i，有a[i]个同学以它为期望
		{
			ans = (ans*(i - counter))%mod; //counter是用来数前面的同学数的. 分数从低往高遍历，对于一个同学而言，他分数可能的取值有i种，
			counter++;                     //而由于每个同学分数各不相同，因此还要减去前面同学的分数个数，总共有counter个
		}
	}
	printf("%d\n", ans);
	return 0;
}