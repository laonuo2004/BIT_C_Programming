#include <stdio.h>
#include <stdlib.h>

typedef struct position
{
	int num;
	unsigned long long x;
	unsigned long long y;
	struct position *next;
}p, *pp;

typedef struct find
{
	struct position *find;
	struct find *next;
}find, *pfind;

pp head = NULL;
pfind fhead = NULL;

void insert(pp p)
{
	pp current = head;
	while(current -> next != NULL)
	{
		if((current -> next -> x)*())
		current = current -> next;
	}
}

void finsert(pfind q)
{
	
}

int main()
{
	head = (pp)malloc(sizeof(p));
	fhead = (pfind)malloc(sizeof(find));
	head -> num = -1;
	head -> x = -1;
	head -> y = -1;
	head -> next = NULL;
	fhead -> find = NULL;
	fhead -> next = NULL;
	int n, i, j, k;
	pp p = NULL;
	pfind q = NULL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
	{
		p = (pp)malloc(sizeof(p));
		q = (pfind)malloc(sizeof(find));
		p -> num = -1;
		scanf("%llu%llu", p -> x, p -> y);
		p -> next = NULL;
		q -> find = p;
		q -> next = NULL;
		insert(p);
		finsert(q);
	}
	return 0;
}