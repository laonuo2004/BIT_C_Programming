#include <stdio.h>
#include <string.h>

int main()
{
	char string[4][50],string_s[4][50] = {'\0'};
	int len[4];
	int min[51][4] = {0};
	for(int i = 1; i <=3; i++)
	{
		gets(string[i]);
		len[i] = strlen(string[i]);
		min[len[i]][i]++;
	}
	for(int i = 1; i <=50; i++)
	{
		for(int j = 1; j<=3; j++)
		{
			if(0 != min[i][j])
			{
				for(int k = 1; k <=50; k++) string_s[j][k] = string[j][k];
				continue;
			}
		}
	}
	for(int i = 1; i <=50; i++)
	{
		int ascii[127] = {0},ascii_a[127][4] = {0};
		for(int j = 1; j <=3; j++)
		{
			ascii[string_s[j][i]]++;
			ascii_a[string_s[j][i]][j]++;
		}
		for(int i = 127; i>=0; i++)
		{
			if(1 == ascii[i])
			{
				for(int j = 1; j<=3; j++)
				{
					if(1 == ascii_a[i][j])
					{
						puts(string_s[j]);
						goto p;
					}
				}	
			}
			else if(ascii[i] > 0)
			{
				for(int j = 1; j<=3; j++)
				{
					if(0 == ascii_a[i][j])
					{
						for(int k = 1; k<=50; k++) string_s[j][k] = '\0';
					}
				}
			}
		}
	}
	p: return 0;
}