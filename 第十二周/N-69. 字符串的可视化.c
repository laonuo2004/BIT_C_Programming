#include<stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int a[3][91] = {0};
	for(int i = 1; i <= 90; i++) a[1][i]=i;
	char s[10001] = {'\0'};
	int max, ascii, max_num, flag;
	gets(s);
	char *p = s;
	while(*p != '\0')
	{
		if(*p >= 'a' && *p <= 'z') *p = *p-32;
		a[2][*p]++;
		*p++;
	}
	for(int i = 65; i <= 89; i++)
	{
		max = a[2][i], ascii = a[1][i], flag = i;
		for(int j = i+1; j <= 90; j++)
		{
			if(a[2][j] > max)
			{
				max = a[2][j];
				ascii = a[1][j];
				flag = j;
			}
			else if(a[2][j] == max && a[1][j] < ascii)
			{
				max = a[2][j];
				ascii = a[1][j];
				flag = j;
			}
		}
		swap(&a[2][flag], &a[2][i]);
		swap(&a[1][flag], &a[1][i]);
	}
	max_num = a[2][65];
	for(int i = 1; i <= max_num; i++)
	{
		int j = 65;
		for(; j <= 89; j++)
		{
			if(a[2][j] >= max_num)
				printf("#");
			else
				printf(" ");
			printf(" ");
			a[2][j]++;
		}
		if(a[2][j] >= max_num)
			printf("#");
		else
			printf(" ");
		printf("\n");
		a[2][j]++;
	}
	int i = 65;
	for(; i <= 89; i++)
	{
		printf("%c ", a[1][i]);
	}
	printf("%c\n", a[1][i]);
	return 0;
}

//教训1：遇到循环最后一个输出格式不一样时，其实直接复制出来就可以了(例如本题打印时最后 j = 90，自动跳出循环去执行下一句，这时 j 已经是90了！所以编号不受影响);
//教训2：循环当中设的 i, j 等算是局部变量，只在循环当中有效，出了循环就被释放了。如果后续还想用的话，可以把 int i = 1 语句放在 for 循环之前;
//教训3：选择排序法最后忘记交换了！ 补充：注意不是把 max 与 开头的交换，而是把 max 所对应的那个位置的数与开头交换！(错误输出：全是Z) 因此需要定义一个 flag 来记录位置；
//教训4：关于 swap 函数：自己写，有几点注意事项：
//		1、定义的是两个指针变量(类型看情况)；
//		2、temp定义为整数即可，不定义为指针；
//		3、传入的是两个要交换的数的地址！(类似传入指针)；
//教训5：自定义函数的时候，用的是逗号隔开，不是分号！注意不像 for 函数一样；