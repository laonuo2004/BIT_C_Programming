#include <stdio.h>

int find(long long x);

long long mutual[5000] = {'\0'};
int main()
{
	long long input[102] = {'\0'}, x;
	int i = 1, j, count_1, count_2 = 0, flag = 0;
	do
	{
		scanf("%lld", &input[i]);
	}while((input[i++]) != -1);
	getchar();
	char lambda = getchar();
	count_1 = i - 2;
	for(i = 1; i <= count_1; i++)
	{
		for(j = 1; j <= count_1; j++)
		{
			if(i == j)
				mutual[++count_2] = input[i];
			else
				if(lambda == '^')
					mutual[++count_2] = input[i]^input[j];
				else
					mutual[++count_2] = input[i]|input[j];
		}
	}
	while((scanf("%lld", &x)) != EOF)
	{
		if(flag++)
			printf(" ");
		printf("%d", find(x));
	}
	printf("\n");
	return 0;
}

int find(long long x)
{
	if(x == 0)
		return 1;
	int i = 0;
	while(mutual[++i] != '\0')
	{
		if(x == mutual[i])
			return 1;
	}
	return 0;
}
//教训1：do while不能省括号！
//教训2：可以巧妙使用++i、i++来使程序更加简洁；
//教训3：之前直接if((char lambda = getchar()) == '^')有问题，因为if语句要求内部为一个条件语句！
//教训4：对于乐学的离谱格式要求：中间为空格，末尾为回车(e.g.0 1\n)，可以换一种输出思路：第一个前面不输出空格，从第二个开始前面输出空格(用一个flag++来判断)，最后回车；
//教训5：注意0也属于G！可以使用一个特判；