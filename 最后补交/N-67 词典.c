#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct word
{
	int num;
	char name[11];
	struct word *next;
}word, *pword;

typedef struct find
{
	struct word *find;
	struct find *next;
}find, *pfind;

pword head = NULL;
pfind head_find = NULL;

void insert(pword p)
{
	pword current = head;
	while(current -> next != NULL)
	{
		if(strcmp(current -> next -> name, p -> name) > 0)
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

void insert_find(pfind q)
{
	pfind current = head_find;
	while(current -> next != NULL)
		current = current -> next;
	current -> next = q;
	return;
}

int main()
{
	head = (pword)malloc(sizeof(word));
	head_find = (pfind)malloc(sizeof(find));
	head -> num = -1;
	int i, j, k;
	for(i = 0; i <= 10; ++i)
		(head -> name)[i] = '\0';
	head -> next = NULL;
	head_find -> find = NULL;
	head_find -> next = NULL;
	int n;
	pword p = NULL;
	pfind q = NULL;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
	{
		p = (pword)malloc(sizeof(word));
		q = (pfind)malloc(sizeof(find));
		p -> next = NULL;
		q -> find = p;
		q -> next = NULL;
		scanf("%s", p -> name);
		insert(p);
		insert_find(q);
	}
	pword current = head -> next;
	i = 0;
	while(current != NULL)
	{
		current -> num = ++i;
		current = current -> next;
	}
	pfind current_find = head_find -> next;
	while(current_find != NULL)
	{
		printf("%d\n", current_find -> find -> num);
		current_find = current_find -> next;
	}
	return 0;
}

//教训1：使用双链表来寻找原来的顺序！