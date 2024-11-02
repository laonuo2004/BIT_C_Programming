#include <stdio.h>

//为什么还有一个过不了？

int main()
{
	int n, counter, a;
	scanf("%d", &n);
	for(int i = 1; i <= n; i+=counter)
	{
//		a = (n%(n/i+1)) == 0? (n/(n/i+1)):(n/(n/i+1)+1);
//		counter = n/(n/i) - ((n%(n/i+1)) == 0? (n/(n/i+1)):(n/(n/i+1)+1)) + 1;
//		a = n/(n/i+1)+1;
		counter = n/(n/i) - (n/(n/i+1)+1) + 1;		
		printf("%d %d\n", n/i, counter);
	}
	return 0;	
}


//GPT给出的代码
/*
int main() {
    int N;
    scanf("%d", &N);
    
    for (int q = N; q > 0; q = N / (N / q + 1)) {
        int lower_bound = N / (q + 1) + 1;
        int upper_bound = N / q;
        printf("%d %d\n", q, upper_bound - lower_bound + 1);
    }
    
    return 0;
}
*/

/* 超时了
int devide(int n, int m)
{
	int m1,std,k=0;
	m1=m;
	std=n/m;
	while(n/m==std)
	{
		k++;
		m++;
	}
	while((m1 != 0) && (n/m1==std))
	{
		k++;
		m1--;
	}
	k--;
	printf("%d %d\n",std, k);
	return k;
}

int main()
{
	int n, counter;
	scanf("%d", &n);
	for(int i = 1; i <= n; i+=counter)
	{
		counter = devide(n, i);
	}
	return 0;
}
*/