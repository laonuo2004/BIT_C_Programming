#include <stdio.h>

int main()
{
	int ascll[26];
	for(int i = 65; i <= 90; i++) ascll[i-65] = i;
	int n;
	scanf("%d", &n);
	if(1 == n) printf("A\n");
	else
	{
		for(int i = 0; i < n; i++) printf("%c", ascll[i%26]); printf("\n");
		for(int i = 1; i <= n-2; i++)
		{
			for(int j = 1; j <= n-i-1; j++) printf(" "); printf("%c\n", ascll[(n+i-1)%26]);
		}
		for(int i = 0; i < n; i++) printf("%c", ascll[(2*n-2+i)%26]); printf("\n");
	}
	return 0;
}