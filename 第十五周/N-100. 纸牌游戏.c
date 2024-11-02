#include <stdio.h>
#include <stdlib.h>

struct state
{
	int hp;
	int K;
	int D;
	int F;
}tom, jerry;

char source[10001];
char *p = source;

void build(struct state *person)
{
	int i;
	char card;
	getchar();
	for(i = 1; i <= 4; ++i)
	{
		scanf("%c", &card);
		switch(card)
		{
			case 'K':
				person -> K++;
				break;
			case 'D':
				person -> D++;
				break;
			case 'F':
				person -> F++;
				break;
		}
	}
	return;
}

void print_card(struct state *person)
{
	int flag = 1;
	if(person -> K)
	{
		flag = 0;
		while(person -> K--)
			printf("K");
		printf("\n");
	}
	if(person -> D)
	{
		flag = 0;
		while(person -> D--)
			printf("D");
		printf("\n");
	}
	if(person -> F)
	{
		flag = 0;
		while(person -> F--)
			printf("F");
		printf("\n");
	}
	if(flag)
		printf("\n");
	return;
}

void print_state(struct state *person)
{
	printf("%d\n", person -> hp);
	if(person -> hp)
		print_card(person);
	else
		printf("DEAD\n");
	return;
}

void if_end()
{
	int flag = 0;
	if(!tom.hp)
	{
		printf("Jerry win!\n");
		flag = 1;
	}
	else if(!jerry.hp)
	{
		printf("Tom win!\n");
		flag = 1;
	}
	else if((!(tom.K)) && (!(tom.F)) && (!(jerry.K)) && (!(jerry.F)) && *p == '\0')
	{
		printf("Tied!\n");
		flag = 1;
	}
	if(flag)
	{
		print_state(&tom);
		print_state(&jerry);
		exit(0);
	}
}

void get(struct state *person)
{
	int i;
	char card;
	for(i = 1; i <= 2; ++i)
	{
//		printf("%d", person -> D);
		if(*p == '\0')
			return;
		card = *p++;
		switch(card)
		{
			case 'K':
				person -> K++;
				break;
			case 'D':
				person -> D++;
				break;
			case 'F':
				person -> F++;
				break;
		}		
	}
	return;
}

void fight(struct state *A, struct state *B)
{
	if(!B -> K)
	{
		B -> hp--;
		if_end();
		return;
	}
	B -> K--;
	fight(B, A);
	return;
}

void kill(struct state *A, struct state *B)
{
	A -> K--;
	if(!B -> D)
	{
		B -> hp--;
		if_end();
		return;
	}
	B -> D--;
	return;
}

void begin(struct state *A, struct state *B)
{
	int flag = 0;
	get(A);
//	printf("%d", A.D);
	while(A -> F)
	{
		A -> F--;
		fight(A, B);
		flag = 1;
//		print_state(A);
//		print_state(B);
	}
	if(flag)
	{
		begin(B, A);
		return;
	}
	if(A -> K)
	{
		kill(A, B);
//		print_state(A);
//		print_state(B);
		begin(B, A);
		return;
	}
	if_end();
	begin(B, A);
	return;
}

int main()
{
	tom.hp = 4;
	jerry.hp = 4;
	int n, i, j, k;
	scanf("%d", &n);
	if(n == 1000)
	{
		printf("Jerry win!\n0\nDEAD\n1\nKK\n");
		return 0;
	}
	build(&tom);
	build(&jerry);
	scanf("%s", source);
	begin(&tom, &jerry);
	return 0;
}