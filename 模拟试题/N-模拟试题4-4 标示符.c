#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct identifier
{
	char name[1000];
	int times;
}ID;

ID table[1000];

int main()
{
	int i, j, k, len, count = 0, flag;
	char ch[1002], ext[1001] = {0};
	char *p = ext;
	scanf("%[^\n]", ch);
	len = strlen(ch);
	for(i = 0; i < len;)
	{
		for(j = i; j <= len; j++)
			if(!((ch[j] >= 'A' && ch [j] <= 'Z') || (ch[j] >= 'a' && ch [j] <= 'z') || (ch[j] >= '0' && ch [j] <= '9') || ch[j] == '_'))
			{
				for(k = i; k < j; k++)
				{
					*p++ = ch[k];
				}
				if(ext[0] >= '0' && ext[0] <= '9')
					goto p;
				flag = 0;
				for(k = 0; k < count; k++)
				{
					if(!strcmp(table[k].name, ext) && strcmp(" ", &ext[0]))
					{
						table[k].times++;
						flag = 1;
						break;
					}
				}
				if(!flag)
				{
					strcpy(table[k].name, ext);
					table[k].times++; 
					count++;
				}
			p:	while(p != ext)
					*--p = 0;
				i = j+1;
			}
//		printf("table:\n");
//		for(j = 0; j < count; j++)
//			printf("%s : %d\n", table[j].name, table[j].times);
	}
	if(!count)
	{
		printf("No identifier!\n");
		exit(0);
	}
	j = 0;
	for(i = 0; i < count; i++)
		if(table[i].times > table[j].times)
			j = i;
	printf("%s\n", table[j].name);
	return 0;
}