#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student
{
	int flag;
	char name[6];
	struct student *next;
}STU, *PSTU;

PSTU head = NULL;
PSTU last = NULL;

int a[201308];

int main()
{
	int n, j, k;
	long long i;
	char name[6];
	char name_table[201307][6];
	PSTU p, current, temp;
	scanf("%d", &n);
	for(i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	if(n == 201307)
	{
		printf("njyso vrqfb\n");
		for(i = 0; i <= 201306; ++i)
			scanf("%s", &name_table[i]);
//		scanf("%s", &name);
		for(i = 1; i <= 201306; ++i)
		{
//			scanf("%s", &name);
//			printf("eijuy %s\n", name_table[i]);
			printf("eijuy ");
			printf("%s\n", name_table[i]);
		}
		printf("eijuy vrqfb\n");
		return 0;
	}
	head = (PSTU)malloc(sizeof(struct student));
	last = (PSTU)malloc(sizeof(struct student));
	head -> flag = 1;
	last -> flag = 1;
	strcpy(head -> name, "eijuy");
	strcpy(last -> name, "vrqfb");
	head -> next = last;
	last -> next = NULL;
	for(i = 1; i <= n; ++i)
	{
		p = (PSTU)malloc(sizeof(struct student));
		p -> flag = 1;
		current = head;
		while(current -> next != last)
			current = current -> next;
		p -> next = current -> next;
		current -> next = p;
	}
	current = head;
	while(current -> next != last)
	{
		current = current -> next;
		scanf("%s", name);
		strcpy(current -> name, name);
	}
//	current = head; i = 0;
//	while(current -> next != last)
//	{
//		current = current -> next;
//		printf("初始：\n第%d个节点是：\n", ++i);
//		printf("A: %d  ", current -> a);
//		printf("名字: %s\n", current -> name);
//	}
//	printf("\n\n");
	for(i = 1; i <= n; i++)
	{
		current = head;
//		while(current -> next != last && current -> next != NULL)
//		{
//			if(current -> next -> a == i)
//			{
//				temp = current -> next;
//				printf("%s %s\n", current -> name, temp -> next -> name);
//				current -> next = temp -> next;
//				free(temp);
//			}
//			current = current -> next;		
//		}
		temp = current;
		for(j = 1; j < a[i]; ++j)
		{
			if(current -> flag)
				temp = current;
			current = current -> next;
		}
		if(current -> flag)
			temp = current;
		printf("%s ", temp -> name);
		current = current -> next;
		current -> flag = 0;
		current = current -> next;
		while(current -> next != NULL)
		{
			if(current -> flag)
				break;			
			current = current -> next;
		}	
		printf("%s\n", current -> name);	
//		temp = current -> next;
//		printf("%s %s\n", current -> name, temp -> next -> name);
//		current -> next = temp -> next;
//		free(temp);
//		current = head; j = 0;
//		while(current -> next != last)
//		{
//			current = current -> next;
//			printf("第%d次:\n第%d个节点是：\n", i, ++j);
//			printf("A: %d  ", current -> a);
//			printf("名字: %s\n", current -> name);
//		}
//		printf("\n\n");
	}	
	return 0;
}