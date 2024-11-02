#include <stdio.h>

int main()
{
	int a[10];
	for(int i=1;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=9;i++)
	{
		int s=0;
		for(int j=1;j<=9;j++)
		{
			if(a[j]==a[i]) s++;
		}
		if(3==s || 1==s)
		{
			printf("%d\n",a[i]);
			break;
		}
	}
	return 0;
}