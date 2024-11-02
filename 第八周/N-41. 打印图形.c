#include <stdio.h>

/*
教训：乐学的编译器版本太老旧了，定义数组时不能含有变量
*/

int main()
{
	int n, k;
	scanf("%d", &n);
	int a[20][20];
	for(int i = 0; i < 2*n-1; i++)
	{
		for(int j = 0; j < 2*n-1; j++)
		{
			a[i][j] = 0;
		}
	}
	int ascll[21], counter = 0;
	for(int i = 98; i <= 122; i++)
	{
		if((101 == i) || (105 == i) || (111 == i) || (117 == i)) counter++;
		else ascll[i-counter-98] = i;
	}
	int _char;
	getchar();
	scanf("%c", &_char);
	getchar();
	if((97 == _char) || (101 == _char) || (105 == _char) || (111 == _char) || (117 == _char)) _char++;
	for(int i = 0; i < 21; i++)
	{
		if(ascll[i] == _char)
		{
			k = i;
			break;
		}
	}
	for(int i = 0; i < 2*n-1; i++)
	{
		a[i][i] = ascll[(i+k)%21];
		a[2*n-2-i][i] = ascll[(i+k)%21];
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 2*n-1-i; j++)
		{
			if(0 == a[i][j]) printf(" ");
			else printf("%c", a[i][j]);
		}
		printf("\n");
	}
	for(int i = n; i < 2*n - 1; i++)
	{
		for(int j = 0; j < i+1; j++)
		{
			if(0 == a[i][j]) printf(" ");
			else printf("%c", a[i][j]);
		}
		printf("\n");
	}	
	return 0;
}