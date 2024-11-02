#include <stdio.h>

int apple(int n)
{
	if(1==n) printf("1\n");
	else if(2==n) printf("2\n");
	else if(3==n) printf("0\n");
	else apple(n-3);
}

int main()
{
	int n;
	scanf("%d",&n);
	apple(n);
	return 0;
}