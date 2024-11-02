#include <stdio.h>
#include <string.h>
#include <ctype.h>

void substring(const char* src, int start, int length, char* dest) {
    int srcLen = strlen(src);
    if (start >= srcLen) {
        dest[0] = '\0';
        return;
    }
    
    int end = start + length;
    if (end > srcLen) {
        end = srcLen;
    }
    
    int i, j;
    for (i = start, j = 0; i < end; i++, j++) {
        dest[j] = src[i];
    }
    dest[j] = '\0';
}

int main()
{
	char s[256] = {'\0'};
	char sub[256][256] = {'\0'};
	gets(s);
	char *temp = s;
	int flag = 0, str = 0;
	while(*temp != '\0')
	{
		if(*temp != ' ')
		{
			int counter = 0;
			while(*temp != ' ' || *temp != '\0')
			{
				counter++;
				*temp++;
			}
			str++;
			substring(s, flag, counter, sub[str]);
			flag = flag + counter;
		}
		flag++;
		*temp++;
	}
	int i = 1;
	for(; i <= str; i++);
	{
		int j = 1;
		sub[i][0] = toupper(sub[i][0]);
		while(sub[str][j] != '\0')
		{
			sub[i][0] = tolower(sub[i][0]);
			j++;
		}
	}
	printf("%s", sub[1]);
	for(int i = 2; i <= str-1; i++)
	{
		if(strcmp(sub[i], ",") == 0 || strcmp(sub[i], ".") == 0)
		{
			printf("%s", sub[i]);
		}
		else
		{
			printf(" %s", sub[i]);
		}
	}
	printf("%s\n", sub[str]);
	return 0;
}