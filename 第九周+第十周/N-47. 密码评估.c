#include <stdio.h>

int number(char s[21])
{
	char *temp = s;
	while(*temp != '\0')
	{
		if(*temp >= '0' && *temp <= '9')
		{
			return 1;
		}
		*temp++;
	}
	return 0;
}

int character(char s[21])
{
	char *temp = s;
	while(*temp != '\0')
	{
		if((*temp >= 'A' && *temp <= 'Z') || (*temp >= 'a' && *temp <= 'z'))
		{
			return 1;
		}
		*temp++;
	}
	return 0;
}

int upper_character(char s[21])
{
	char *temp = s;
	while(*temp != '\0')
	{
		if(*temp >= 'A' && *temp <= 'Z')
		{
			return 1;
		}
		*temp++;
	}
	return 0;
}

int lower_character(char s[21])
{
	char *temp = s;
	while(*temp != '\0')
	{
		if(*temp >= 'a' && *temp <= 'z')
		{
			return 1;
		}
		*temp++;
	}
	return 0;
}

int other(char s[21])
{
	char *temp = s;
	while(*temp != '\0')
	{
		if((*temp < '0') || (*temp > '9' && *temp < 'A') || (*temp > 'Z' && *temp < 'a') || (*temp > 'z'))
		{
			return 1;
		}
		*temp++;
	}
	return 0;
}

int main()
{
	int t, i = 1;
	scanf("%d", &t);
	getchar();
	int counter[1001] = {0};
	char s[1001][21] = {'\0'};
	char ans[1001][10] = {'\0'};
	while(i++<=t)
	{
		scanf("%d", &counter[i]);
		scanf("%s", s[i]);
	}
	for(int i = 1; i <=t; i++)
	{
		if(counter[i] < 6 || (number(s[i])+character(s[i])) != 2)
		{
			printf("INVALID\n");
		}
		else if(counter[i] <= 10 && other(s[i]) == 0 && (upper_character(s[i])+lower_character(s[i])) == 1)
		{
			printf("RUO\n");
		}
		else if(counter[i] > 10 && (other(s[i])+upper_character(s[i])+lower_character(s[i])) == 3)
		{
			printf("QIANG\n");
		}
		else
		{
			printf("ZHONG\n");
		}
	}
	return 0;
}