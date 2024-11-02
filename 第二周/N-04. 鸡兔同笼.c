#include <stdio.h>

int main()
{
	int head,foot,chicken,rabbit,delta;
	scanf("%d%d",&head,&foot);
	delta = foot - head*2;
	rabbit = delta/2;
	chicken = head - rabbit;
	printf("%d %d\n",chicken,rabbit);
	return 0;
}