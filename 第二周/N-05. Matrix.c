#include <stdio.h>

int main()
{
	int a[3][3];
	for (int i=0;i<=2;i++)
	{
		for (int j=0;j<=2;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for (int i=0;i<=2;i++)
	{
		for (int j=0;j<=1;j++)
		{
			printf("%d ",a[j][i]);
		}
		
		printf("%d\n",a[2][i]);
	}
	return 0;
}