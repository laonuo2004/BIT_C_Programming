#include <stdio.h>

char upper(char ch)
{
	if(ch >= 'a' && ch <= 'z')
		return ch-32;
	else
		return ch;	
}

char lower(char ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return ch+32;
	else
		return ch;
}

int main()
{
	char str[256] = {0}, newstr[256] = {0};
	scanf("%[^\n]", str);
	char *p = str, *q = NULL, *object = newstr, *temp = newstr, lastch = ' ', flag = 1;
	while(*p != '\0')
	{
		if(*p == ',' || *p == '.')
		{
			q = p-1;
			while(*q == ' ')
				*q-- = '#';
		}
		*p++;
	}
	p = str;
	while(*p != '\0')
	{
		if(*p == ' ' && lastch != ' ')
		{
			lastch = ' ';
//			printf("%c", lastch);
			*object++ = lastch;
		}
		else if((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z'))
		{
			lastch = *p;
			if(flag)
			{
//				printf("%c", upper(*p));
				*object++ = upper(*p);
				flag = 0;
			}
			else
//				printf("%c", lower(*p));
				*object++ = lower(*p);
		}
		else if(*p == ',' || *p == '.')
		{
//			printf("%c ", *p);
			*object++ = *p;
			*object++ = ' ';
			lastch = ' ';
			if(*p == '.')
				flag = 1;
		}
		*p++;
	}
	while(temp != object-1)
		printf("%c", *temp++);
	printf("\n");
	return 0;
}