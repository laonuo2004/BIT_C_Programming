#include <stdio.h>

int main()
{
	int a11,a12,a21,a22,determinant;
	scanf("%d%d%d%d",&a11,&a12,&a21,&a22);
	determinant = a11*a22-a12*a21;
	printf("determinant=%d\n",determinant);
	return  0;
}