#include <stdio.h>

int main()
{
	float a,b;
	float r;
	scanf("%f%f",&a,&b);
	r=(a*60+b)/2-b*6;
	r=r>=0?r:-r;
	r=r<=180?r:360-r;
	printf("At %.0f:%02.0f the angle is %.1f degrees.\n",a,b,r);
	return 0;
}

/*int gcd(float x)
{
	return x>=0?x:-x;
}*/