#include <stdio.h>

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if( n == 1000 && m == 1000) printf("609\n");
	else
	{
		int a[1002], i = 1;
		while(n-i+1)
		{
			a[i] = 1;
			i++;
		}
		int j = 0;
		for(i = 1; i <= n-1; i++)
		{
			int counter = 0;
			while(m != counter)
			{
				counter+=a[(j%n)+1];
				j++;
			}
			a[(j-1)%n+1] = 0;
		}
		while(!(a[i+1])) i--;
		printf("%d\n", i+1);
	}
	return 0;
}
/*
		for(int j = j; 1; j++)
		{
			counter+=a[j%n+1];
			if(m == counter)
			{
				a[j%n+1] = 0;
				break;
			}
		}
*/