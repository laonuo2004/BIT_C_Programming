#include <stdio.h>

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	printf("%c", 43); for(int i = 1; i <= m - 2; i++) printf("%c", 45); printf("%c\n", 43);
	for(int i = 1; i <= k - 2; i++)
	{
		printf("%c", 124); for(int k = 1; k <= m - 2; k++) printf("%c", 46); printf("%c\n", 124);
	}
	printf("%c", 60); for(int i = 1; i <= m - 2; i++) printf("%c", 61); printf("%c\n", 62);
	for(int i = 1; i <= n - k - 1; i++)
	{
		printf("%c", 124); for(int k = 1; k <= m - 2; k++) printf("%c", 46); printf("%c\n", 124);
	}
	printf("%c", 43); for(int i = 1; i <= m - 2; i++) printf("%c", 45); printf("%c\n", 43);
	return 0;
}