#include <stdio.h>

int main()
{
	char ch;
	ch = getchar();
	if (ch >= 48 && ch <= 57) printf("Digital.\n");
	else if (ch >= 65 && ch <= 90) printf("Upper case letter.\n");
	else if (ch >= 97 && ch <= 122) printf("Lower case letter.\n");
	else printf("Other.\n");
	return 0;
}