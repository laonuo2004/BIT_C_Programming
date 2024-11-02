#include <stdio.h>

int main()
{
	int n,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int k=0;
		if(6==i%10) k++;
		if(6==i/10%10) k++;
		if(6==i/100%10) k++;
		if(6==i/1000%10) k++;
		switch(k)
		{
			case 1:
				m+=6;
				break;
			case 2:
				m+=66;
				break;
			case 3:
				m+=666;
				break;
			case 4:
				m+=6666;
				break;
		}
	}
	printf("%d\n",m);
	return 0;
}