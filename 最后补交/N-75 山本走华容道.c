#include <stdio.h>

int main()
{
	int t, m, n, x, y, i, j, k;
	scanf("%d", &t);
	for(i = 1; i <= t; ++i)
	{
		scanf("%d%d%d%d", &m, &n, &x, &y);
		if((m-x)^(n-y)^(x-1)^(y-1))
			printf("win\n");
		else
			printf("lose\n");
	}
	return 0;
}