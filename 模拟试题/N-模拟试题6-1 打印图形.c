#include <stdio.h>
#include <string.h>

int main()
{
	int n, m, i = 0, j, k, counter = 0, len;
	char str[100] = {'0'};
	char *p = str;
	scanf("%d%d%s", &n, &m, str);
	printf("%3d:", ++i);
	while(m)
	{
		len = strlen(str);
		while(len)
		{
			printf("%c", *p);
			*p++; counter++;
			if(*p == '\0')
				p = str;
			if(counter >= n)
			{
				if(m == 1 && p == str);
				else
					printf("\n%3d:", ++i);
				counter = 0;
			}
			len--;
		}
		m--;
	}
	printf("\n");
	return 0;
}