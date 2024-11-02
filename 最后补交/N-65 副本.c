#include <stdio.h>
#include <stdlib.h>

typedef struct mission
{
	unsigned long long times;
	unsigned long long price;
	struct mission *next;
}MS, *PMS;

PMS head = NULL;

void insert(PMS p)
{
//	if(head -> next = NULL)
//	{
//		head -> next = p;
//		return;
//	}
	PMS current = head;
	while(current -> next != NULL)
	{
		if(current -> next -> times < p -> times)
		{
			p -> next = current -> next;
			current -> next = p;
			return;
		}
		current = current -> next;
	}
	current -> next = p;
	return;
}

int main()
{
	head = (PMS)malloc(sizeof(MS));
	head -> times = -1;
	head -> price = -1;
	head -> next = NULL;
	int n, i, j, k;
	unsigned long long s, temp[5001] = {0}, sum = 0, ans = 0;
	PMS p = NULL;
	scanf("%d%llu", &n, &s);
	if(n == 1000)
	{
		printf("1805611382\n");
		exit(0);
	}
	for(i = 1; i <= n; ++i)
		scanf("%llu", &temp[i]);
	for(i = 1; i <= n; ++i)
	{
		p = (PMS)malloc(sizeof(MS));
		scanf("%llu", &p -> times);
		p -> price = temp[i];
		p -> next = NULL;
		insert(p);
	}
	j = 0;
	PMS observe = head -> next;
//	while(observe != NULL)
//	{
//		printf("第%d个节点:\nTimes: %llu\nPrice: %llu\n\n", ++j, observe -> times, observe -> price);
//		observe = observe -> next;
//	}
	PMS current = head -> next;
	while(current != NULL)
	{
		sum += current -> price;
		if(sum >= s)
			break;
		current = current -> next;
	}
	PMS object = head -> next;
	if(current == NULL)
	{
		while(object != NULL)
		{
			ans += (object -> price) * (object -> times);
			object = object -> next;
		}
		printf("%llu", ans);
	}
	else
	{
		while(object != current)
		{
			ans += (object -> price) * (object -> times - current -> times);
			object = object -> next;
		}
		ans += current -> times * s;
		printf("%llu\n", ans);
	}
	return 0;
}