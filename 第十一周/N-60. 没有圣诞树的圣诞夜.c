#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int loop_1 = (n+2)/3 - 1;
	for(int i = 1; i <= loop_1; i++)
	{
		for(int j = 1; j <= 3; j++)
		{
			int loop_1_1 = ((n+2)/3-1)*4 - 2*i*(j-1), loop_1_2 = 3+4*(j-1)*i;
			for(int k = 1; k <= loop_1_1; k++) printf(" ");
			for(int k = 1; k <= loop_1_2; k++) printf("*");
			printf("\n");
		}
	}
	int loop_2 = n - 3*loop_1;
	for(int i = 1; i <= loop_2; i++)
	{
		int loop_2_1 = ((n+2)/3-1)*4;
		for(int j = 1; j <= loop_2_1; j++) printf(" ");
		for(int j = 1; j <= 3; j++) printf("*");
		printf("\n");
	}
	return 0;
}

//教训1：i <= (n+2)/3 用于判断错位除法
//教训2：循环判断条件可以另外设一个变量 int loop =，方便debug
//教训3：养成纸上演算的习惯，不要总是头脑风暴