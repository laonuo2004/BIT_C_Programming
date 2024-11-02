#include <stdio.h>

int main()
{
	int m,q,v,b;
	int Q,B,V;
	float r;
	scanf("%d%d%d%d%d%d",&m,&q,&v,&b,&Q,&B);
	r=(float)(m*v)/(q*b);
	V=Q^B;
	printf("%.2f %d\n",r,V);
	return 0;
}