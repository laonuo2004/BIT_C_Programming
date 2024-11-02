#include <stdio.h>
#include <stdlib.h>

int main()
{
	int stack[3000] = {'\0'}, output[3000] = {'\0'};
	int *head = stack, *end = stack, *p = NULL, *out = output, *print = output;
	char cmd[9] = {'\0'}, num[7] = {'\0'};
	while (scanf("%s", &cmd) != EOF)
	{
		if(cmd[1] == 'u')
		{
			*end = atoi(&cmd[5]);
//			printf("%d", *end);
			*end++;
		}
		if(cmd[1] == 'o')
		{
			if(end != head)
			{
				*end--;
				*out = *end;
				*out++;
				*end = 0;
			}
		}
		if(cmd[1] == 'e')
		{
			p = head;
			if(p == end)
				printf("\n");
			else
				while(p != end)
				{
					printf("%d", *p);
					if(p+1 == end)
						printf("\n");
					else
						printf(" ");
					*p++;
				}
		}
	}
	if(end != head)
	{
		while((end+1) != head)
		{
			*end--;
			*out = *end;
			*out++;
		}
		while(*(print+1) != '\0')
		{
			printf("%d ", *print);
			*print++;
		}
		printf("%d\n", *print);
	}
	return 0;
}

//教训1：stdlib.h 中 atoi 函数的使用：注意！该函数要求数字前面不能有别的东西！空格可以；
//教训2：不知道为什么总是有一个样例过不去？！