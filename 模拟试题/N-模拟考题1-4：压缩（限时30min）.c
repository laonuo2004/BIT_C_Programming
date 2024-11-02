#include <stdio.h>

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	char s[201308] = {0}, ans[201308] = {0};
	char last = '\0';
	char *p = ans;
	scanf("%s", s);
	for(i = 0; i < n; ++i)
		if(last != s[i])
		{
			*p++ = s[i];
			last = s[i];
		}
	printf("%s\n", ans);
	return 0;
}