#include <stdio.h>

int main()
{
	int n, k, clock;
	scanf("%d%d%d", &n, &k, &clock);
	int info[5001][3] = {0}, joseph[5001] = {0}, counter = 0, flag = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= 2; j++)
		{
			scanf("%d", &info[i][j]);
		}
	}
	for(int i = 1; i <= n-1; i++)
	{
		for(int j = 1; ; j++)
		{
			if(joseph[flag] == 0)
			{
				counter++;
				if(counter == k)
				{
					joseph[flag] = 1;
					flag = flag%n+1;
					counter = 0;
					break;
				}
				flag = flag%n+1;
			}
			else
				flag = flag%n+1;
		}
	}
	for(int i = flag; ; i++)
	{
		flag = flag%n+1;
		if(joseph[flag] == 0) break;
	}
	if(clock == 0)
	{
		printf("%d,%d,%d\n", flag, info[flag][1], info[flag][2]);
	}
	else
	{
		if(flag == 1)
			printf("%d,%d,%d\n", flag, info[flag][1], info[flag][2]);
		else
			printf("%d,%d,%d\n", n+2-flag, info[n+2-flag][1], info[n+2-flag][2]);
	}
	return 0;
}

//教训1：先计数，再判断，最后再flag++！；
//教训2：增大的回路用求余，减小的回路用什么？用三目运算符 flag = (flag-1)==0?flag+4:flag-1;
//教训3：注意最后还得要再往前找幸存者！最后的 flag 是被踢出的人的编号 +1；