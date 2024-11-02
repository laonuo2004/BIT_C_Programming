#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int l, r, counter = 0, result;
		scanf("%d%d", &l, &r);
		while(r)
		{
			if(l == r)
			{
				break;
			}
			l>>=1; r>>=1;
			counter++;
		}
		result = l<<counter;
		printf("%d\n", result);
	}
	return 0;
}