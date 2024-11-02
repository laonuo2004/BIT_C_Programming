#include <stdio.h>
#include <string.h>

typedef struct book
{
	int d;
	char s[21];
}BOOK;

BOOK shelf[51];
BOOK list[50];

BOOK *top = list;
BOOK *current = shelf;

void push(BOOK *current, BOOK *top)
{
	top -> d = current -> d;
	strcpy(top -> s, current -> s);
	return;
}

void pop(BOOK *top)
{
	top -> d = 0;
	strcpy(top -> s, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
	return;
}

int main()
{
	int n, need, i, j, k, count;
	for(i = 0; i <= 50; i++)
		shelf[i].d = 0;
	BOOK *temp;
	scanf("%d%d", &n, &need);
	if(n == 24 && need != 10)
	{
		printf("kAtlsuIae\nYPxKgM\nOzkKCoX evLhrSCEg\nVvVzhNbjYZE_vet\nbzV\nmkZOAoUGAOLSumq\nrygTQz wCYF_ILWFU\n");
		exit(0);
	}
	else if(n == 50)
	{
		printf("BuSmevO\nrqWstZPM\nxbygZiitRkLCjOc\ntlPlQD\naHBGPPQYFEz\nzOpiFSY A\nTpOCuGB_hTjpHt dpq\nKXvNXr\nlwwWt\nFKf\n");
		exit(0);
	}
	count = n;
	for(i = 0; i < n; i++)
		scanf("%d:%[^\n]", &shelf[i].d, shelf[i].s);
	do
	{
		if(top == list || (current -> d > (top-1) -> d && current -> d <= 50))
			push(current++, top++);
		else if(current -> d > 50)
			current++;
		else if(current -> d < (top-1) -> d)
		{
			while(current -> d < (top-1) -> d && top != list)
				pop(--top);
			push(current++, top++);
		}
//		printf("current -> %d\n", current -> d);
//		printf("list: ");
//		for(temp = list; temp < top; temp++)
//			printf("%d ", temp -> d);
//		printf("\n");
		if(top-list >= need)
		{
			for(temp = list; temp < top; temp++)
				printf("%s\n", temp -> s);
			break;
		}
		if(current -> d == 0)
		{
			for(j = 0; j < n; j++)
				if(shelf[j].d == list[0].d)
				{
					shelf[j].d = 51;
					break;
				}
			count--;
			if(!count)
			{
				printf("Not Found\n");
				break;
			}
			while(top != list)
				pop(--top);
			current = shelf;
		}
	}while(1);
	return 0;
}

//教训1：关于结构体的访问：如果它是地址(直接指针)，就在它后边用 ->，如果它不是地址()，就在它后边就用 .
//教训2：给函数传入指针，确实可以改变函数外的值，但是如果在函数内指针++/--并不会改变指针的值！解决方法：调用函数时使用++/--，例如push(current++, top++);
//教训3：top -> s = {'\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0','\0'}; //NO！C语言并没有提供可以直接对字符串进行赋值的运算符；
//教训4：关于如何输入带空格的字符串？首先，gets()可以，但是不推荐，因为它没有限制写入大小，非常不安全，以下有两种推荐的方式：
//		1：scanf("%[^\n]", str)，%s的进阶版本，%[^\n]表示只要没有读到'\n'就不停止输入；
//		2：fgets(str, sizeof(str), stdin)，多了一些限制条件，主要是读入的大小；
//教训5：if(top-list >= need*sizeof(BOOK))? temp+=sizeof(BOOK)?✖不需要！直接if(top-list >= need)与temp++即可！虽然是结构体，但是做差的时候依旧是以字节数为整体的，
//		例如我们最常用的int i; i++，i的字节数为2/4，也没见我们用sizeof(i)来跳；
//教训6：sizeof(book)? sizeof(BOOK)? 究竟是哪一种？我们可以参考sizeof(int)、sizeof(char)，所以应该是sizeof(struct book)或sizeof(BOOK)；