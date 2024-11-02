#include <stdio.h>

typedef struct data
{
	int num;
	int flag;
}DATA;

DATA array[201308];

int changed[201308], *p = changed;

int main()
{
	int n, m, i, j, k, t, x, lazy = 0;
	int *q = NULL;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++i)
		scanf("%d", &array[i].num);
	for(i = 1; i <= m; ++i)
	{
		scanf("%d%d", &t, &x);
		switch(t)
		{
			case 0:
				lazy += x;
				for(q = changed; q < p; q++)
					array[*q].num += x;
				break;
			case 1:
				if(array[x].flag)
					array[x].num = -array[x].num;
				else
				{
					array[x].num = -(array[x].num+lazy);
					array[x].flag = 1;
					*p++ = x;
				}
				break;
		}
//		printf("操作后：\n");
//		for(j = 1; j <= n; ++j)
//			if(array[j].flag)
//				printf("%d ", array[j].num);
//			else
//				printf("%d ", array[j].num+lazy);
//		printf("\n");
	}
	for(i = 1; i <= n; ++i)
		if(array[i].flag)
			printf("%d\n", array[i].num);
		else
			printf("%d\n", array[i].num+lazy);
	return 0;
}