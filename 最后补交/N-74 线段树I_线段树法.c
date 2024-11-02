#include <stdio.h>
#define MAX 201308

int array[MAX], tree[MAX<<2], lazy_add[MAX<<2], lazy_plus[MAX<<2];

void pushdown(int s, int t, int p)
{
	if(s == t)
		return;
	int mid = s + ((t-s)>>1);
	if((lazy_add || lazy_plus[p] != 1 ) && s != t)
	{
		tree[p<<1] = tree[p<<1]*lazy_plus[p]+(mid-s+1)*lazy_add[p];
		lazy_add[p<<1] = lazy_add[p<<1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1] *= lazy_plus[p];
		tree[p<<1|1] = tree[p<<1|1]*lazy_plus[p]+(t-mid)*lazy_add[p];
		lazy_add[p<<1|1] = lazy_add[p<<1|1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1|1] *= lazy_plus[p];
		lazy_add[p] = 0;
		lazy_plus[p] = 1;
	}
	pushdown(s, mid, p<<1);
	pushdown(mid+1, t, p<<1|1);
	return;
}

void build(int s, int t, int p)
{
	if(s == t)
	{
		tree[p] = array[s];
		return;
	}
	int mid = s + ((t-s)>>1);
	build(s, mid, p<<1);
	build(mid+1, t, p<<1|1);
	tree[p] = tree[p<<1]+tree[p<<1|1];
	return;
}

void add(int s, int t, int l, int r, int p, int delta)
{
	if(s >= l && t <= r)
	{
		tree[p] += (t-s+1)*delta;
		lazy_add[p] += delta;
		return;
	}
	int mid = s + ((t-s)>>1);
	if((lazy_add || lazy_plus[p] != 1 ) && s != t)
	{
		tree[p<<1] = tree[p<<1]*lazy_plus[p]+(mid-s+1)*lazy_add[p];
		lazy_add[p<<1] = lazy_add[p<<1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1] *= lazy_plus[p];
		tree[p<<1|1] = tree[p<<1|1]*lazy_plus[p]+(t-mid)*lazy_add[p];
		lazy_add[p<<1|1] = lazy_add[p<<1|1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1|1] *= lazy_plus[p];
		lazy_add[p] = 0;
		lazy_plus[p] = 1;
	}
	if(l <= mid)
		add(s, mid, l, r, p<<1, delta);
	if(r > mid)
		add(mid+1, t, l, r, p<<1|1, delta);
	tree[p] = tree[p<<1]+tree[p<<1|1];
	return;
}

void plus(int s, int t, int l, int r, int p, int multiplier)
{
	if(s >= l && t <= r)
	{
		tree[p] *= multiplier;
		lazy_plus[p] *= multiplier;
		return;
	}
	int mid = s + ((t-s)>>1);
	if((lazy_add || lazy_plus[p] != 1 ) && s != t)
	{
		tree[p<<1] = tree[p<<1]*lazy_plus[p]+(mid-s+1)*lazy_add[p];
		lazy_add[p<<1] = lazy_add[p<<1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1] *= lazy_plus[p];
		tree[p<<1|1] = tree[p<<1|1]*lazy_plus[p]+(t-mid)*lazy_add[p];
		lazy_add[p<<1|1] = lazy_add[p<<1|1]*lazy_plus[p]+lazy_add[p];
		lazy_plus[p<<1|1] *= lazy_plus[p];
		lazy_add[p] = 0;
		lazy_plus[p] = 1;
	}
	if(l <= mid)
		plus(s, mid, l, r, p<<1, multiplier);
	if(r > mid)
		plus(mid+1, t, l, r, p<<1|1, multiplier);
	tree[p] = tree[p<<1]+tree[p<<1|1];
	return;
}

int find(int s, int t, int i, int p)
{
	if(s == t)
		return p;
	int mid = s + ((t-s)>>1);
//	if((lazy_add || lazy_plus[p] != 1 ) && s != t)
//	{
//		tree[p<<1] = tree[p<<1]*lazy_plus[p]+(mid-s+1)*lazy_add[p];
//		lazy_add[p<<1] = lazy_add[p<<1]*lazy_plus[p]+lazy_add[p];
//		lazy_plus[p<<1] *= lazy_plus[p];
//		tree[p<<1|1] = tree[p<<1|1]*lazy_plus[p]+(t-mid)*lazy_add[p];
//		lazy_add[p<<1|1] = lazy_add[p<<1|1]*lazy_plus[p]+lazy_add[p];
//		lazy_plus[p<<1|1] *= lazy_plus[p];
//		lazy_add[p] = 0;
//		lazy_plus[p] = 1;
//	}
	if(i > mid)
		find(mid+1, t, i, p<<1|1);
	else
		find(s, mid, i, p<<1);
}

int main()
{
	int n, m, t, x, i, j, k;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; ++i)
		scanf("%d", &array[i]);
	for(i = 1; i <= MAX<<2; ++i)
		lazy_plus[i] = 1;
	build(1, n, 1);
//	i = 1;
//	while(tree[i])
//		printf("%d ", tree[i++]);
	for(i = 1; i <= m; ++i)
	{
		scanf("%d%d", &t, &x);
		switch(t)
		{
			case 0:
				add(1, n, 1, n, 1, x);
				break;
			case 1:
				plus(1, n, x, x, 1, -1);
				break;
		}
	}
	pushdown(1, n, 1);
	for(i = 1; i <= n; ++i)
		printf("%d\n", tree[find(1, n, i, 1)]);
	return 0;
}

//教训1：小心运算优先级！乘除>加减>移位运算!建树的时候要加括号！