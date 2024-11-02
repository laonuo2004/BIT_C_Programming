#include <stdio.h>

unsigned long long card[6];

int main()
{
	int n, i, j, k, min, ans = 0;
	unsigned long long buy;
	scanf("%d%llu", &n, &buy);
	for(i = 1; i <= n; ++i)
		scanf("%llu", &card[i]);
	while(buy)
	{
		min = 1;
		for(i = 1; i <= n; ++i)
			if(card[i] < card[min])
				min = i;
		card[min]++;
		buy--;
	}
//	printf("%llu ", card[min]);
	min = 1;
	for(i = 1; i <= n; ++i)
		if(card[i] < card[min])
			min = i;	
	for(i = 1; i <= n; ++i)
		if(card[i] > card[min])
			ans++;			
	printf("%llu %d\n", card[min], ans);
	return 0;
}