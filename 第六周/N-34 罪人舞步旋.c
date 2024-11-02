#include <stdio.h>

unsigned long long quick_power(unsigned long long a, unsigned long long b)
{
	while(!(b&1))
	{
		a = ((a%998244353)*(a%998244353))%998244353;
		b >>= 1;
	}
	if(!(b^1)) return a;
	else
	{
		b--;
		return ((a%998244353)*(quick_power(a, b)%998244353))%998244353;
	}
}

int main()
{
	unsigned long long v, t, x;
	scanf("%llu%llu%llu", &v, &t, &x);
//	unsigned long long t, x, ans = 1;
//	scanf("%llu%llu", &t, &x);
	if(t&1)
	{
		t--;
		v = ((v%998244353)*x)%998244353;
	}
	v = ((v%998244353)*(quick_power(x, t)%998244353))%998244353;
	printf("%llu\n", v);
	return 0;
}