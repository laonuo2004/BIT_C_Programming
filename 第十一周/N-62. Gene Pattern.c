#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[101][51] = {'\0'};
	int b[51] = {'\0'};
	int counter = 1;
	while(scanf("%d", &a[counter][1]) != EOF)
	{
		for(int j = 2; j <= n; j++)
		{
			scanf("%d", &a[counter][j]);
		}
		counter++;
	}
	counter--;
	for(int i = 1; i <= counter; i++)
	{
		for(int j = i+1; j <= counter; j++)
		{
			for(int k = 1; k <= n; k++)
			{
				b[a[i][k]] = b[a[i][k]]+((a[i][k]^a[j][k]) != 0);
			}
		}
	}
	int MAX = 0, id = 1, count = 0;
	for(int i = 1; i <= n; i++)
	{
		if(b[i] > MAX)
		{
			MAX = b[i];
			count = 1;
			id = i;
		}
		else if(b[i] == MAX)
		{
			count++;
		}
	}
	if(count != 1) printf("-1\n");
	else printf("%d\n", id);
	return 0;
}

//教训1：乐学+自己的gcc好像都不支持动态数组，因此一定要借助好题目给出的范围来开长度！
//教训2：对于不知道输入次数的情况，怎么操作？还是得要用到万能的 while(scanf()!=EOF)；
//教训3： b[k] = b[k]+((a[i][k]^a[j][k]) != 0) 这一行一定要注意好运算优先级！先逻辑运算后位运算，因此要套括号；
//教训4： b[k] = b[k]+((a[i][k]^a[j][k]) != 0) 注意下标不应该是 k，而应该是 a[i][k]所对应的那个数！这在非 1 2 3…… 序列中就会出现问题；