#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	char s[1001] = {'\0'};
	scanf("%s", s);
	char *temp = s;
	while(*temp != '\0')
	{
		if(*temp >= 'A' && *temp <= 'Z')
		{
			*temp = *temp-65-7<0?*temp-7+26:*temp-7;
		}
		else
		{
			*temp = *temp-97-7<0?*temp-7+26:*temp-7;
		}
		printf("%c", *temp);
		*temp++;
	}
	printf("\n");
	return 0;
}