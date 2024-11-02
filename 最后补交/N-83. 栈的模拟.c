#include <stdio.h>
#include <stdlib.h>

int stack[3000], pop_out[3001], *top = stack, *top_pop = pop_out;

void push(int insert)
{
	*top++ = insert;
}

void pop()
{
	if(top != stack)
		*top_pop++ = *--top;
}

void sequence()
{
	int *current = stack;
	if(current != top)
	{
		printf("%d", *current++);
		while(current != top)
			printf(" %d", *current++);
	}
	printf("\n");
}

int main()
{
	int i = 1;
	char command[20] = {0};
	while(scanf("%s", command) != EOF)
	{
		switch(command[1])
		{
			case 'u':
				push(atoi(&command[5]));
				break;
			case 'o':
				pop();
				break;
			case 'e':
				sequence();
				break;
		}
	}
	int flag = 0;
	int *current = pop_out;
	if(current != top_pop)
	{
		flag = 1;
		printf("%d", *current++);
		while(current != top_pop)
			printf(" %d", *current++);
	}
	current = top;
	if(current != stack)
	{
		if(flag)
		{
			while(current != stack)
				printf(" %d", *--current);
		}
		else
		{
			printf("%d", *--current);
			while(current != stack)
				printf(" %d", *--current);
		}
		flag = 1;
	}
	if(flag)
		printf("\n");
	return 0;
}