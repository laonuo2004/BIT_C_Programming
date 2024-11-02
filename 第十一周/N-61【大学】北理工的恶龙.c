#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if(n > m) printf("bit is doomed!\n");
	else
	{
		int a[102] = {0}, b[102] = {0};	
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &a[0]);
			for(int j = n; j >= 1; j--)
			{
				a[j+1] = a[j];
				if(a[j-1] >= a[0])
				{
					a[j] = a[0];
					break;
				}
			}
		}
		for(int i = 1; i <= m; i++)
		{
			scanf("%d", &b[0]);
			for(int j = m; j >= 1; j--)
			{
				b[j+1] = b[j];
				if(b[j-1] >= b[0])
				{
					b[j] = b[0];
					break;
				}
			}
		}
		int counter = 0, flag = m+1;
		for(int i = n; i >= 1; i--)
		{
			for(int j = flag-1; j >= 1; j--)
			{
				if(m-j<n-i)
				{
					printf("bit is doomed!\n");
					return 0;
				}
				if(b[j] >= a[i])
				{
					flag = j;
					a[i] = 0;
					counter = counter+b[j];
					break;
				}
			}
		}
		if(0 == a[1]) printf("%d\n", counter);
		else printf("bit is doomed!\n");
	}
	return 0;
}

//教训1：关于插入排序法的几点注意
//		1、数组多开两个格子；
//		2、先把数字输入到 a[0] 当中，既节省空间，也方便比较；
//		3、逆序时做两件事： (1)顺带把数字往后挪： a[j+1] = a[j] (2)判断前一个数与输入的数的大小关系，到了就插入，一定要记得 break ！！！；
//教训2：从后往前遍历！因为数组是从大到小排的，这点一定要记住！(因为是个人特色)；
//教训3：记得加 break！
//教训4：可能会存在砍不下来的情况