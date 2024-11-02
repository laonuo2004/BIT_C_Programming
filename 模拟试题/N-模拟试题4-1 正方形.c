#include <stdio.h>

char up(char ch)
{
	if(ch >= 'a' && ch <= 'z')
		return ch-32;
	else
		return ch;
}

int main()
{
	int n, table[100][100] = {0}, i, j, k;
	char ch;
	scanf("%d %c", &n, &ch);
	ch = up(ch);
	if(ch < 'A' || ch > 'Z')
	{
		printf("Input error!\n");
		return 0;
	}
	for(i = 0; i < n; i++)
	{
		table[0][i] = ch;
		table[i][0] = ch;
		ch = (ch+1-65)%26+65;
	}
	for(i = 1; i < n; i++)
	{
		table[n-1][i] = ch;
		table[i][n-1] = ch;
		ch = (ch+1-65)%26+65;
	}
	for(i = 0 ; i < n ;i++)
	{
		printf("%c", table[i][0]);
		for(j = 1; j < n; j++)
			if(table[i][j] >= 'A' && table[i][j] <= 'Z')
				printf(" %c", table[i][j]);
			else
			{
				printf("  ");
			}
		printf("\n");
	}
	return 0;
}

//教训1：关于字符型变量的char、int关系：确实是ASCII码一一对应的，但是有时候会看到输出出来是32之类的，不是因为这个关系错了，而是因为在输入的时候输入了空格！
//		（小心scanf中的%c！会吸空格、回车）