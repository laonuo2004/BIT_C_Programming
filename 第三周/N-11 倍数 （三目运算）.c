#include <stdio.h>

int main()
{
	int n,m,k;
	scanf("%d%d",&n,&m);
	if(0==m)
	{
		if(n!=0) printf("No\n");
		else printf("Yes\n");
	}
	else
	{
		k=n%m;
		switch(k)
		{
			case 0:
				printf("Yes\n");
				break;
			default:
				printf("No\n");
		}
	}
	return 0;
}