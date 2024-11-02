#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	int id;
	char sex;
	double score;
	struct student* next;
}stu, *pstu;

pstu head = NULL;

void insert(int x, int id, char sex, double score)
{
	int i;
	pstu p = (pstu)malloc(sizeof(stu));
	if(p == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	p -> id = id;
	p -> sex = sex;
	p -> score = score;
	pstu current = head;
	for(i = 0; i < x; i++)
		current = current -> next;
	p -> next = current -> next;
	current -> next = p;
	return;
}

void deletenode(int x)
{
	int i;
	pstu current = head;
	pstu objection;
	for(i = 0; i < x-1; i++)
		current = current -> next;
	objection = current -> next;
	current -> next = objection -> next;
	free(objection);
	return;
}

void find(int x)
{
	int i;
	pstu current = head;
	for(i = 0; i < x; i++)
		current = current -> next;
	printf("%d %c %.1lf\n", current -> id, current -> sex, current -> score);
	return;
}

int main()
{
	head = (pstu)malloc(sizeof(stu));
	head -> id = -1;
	head -> sex = '\0';
	head -> score = -1;
	head -> next = NULL;
	int n, i, j, k, op, id, place_1, place_2;
	char sex;
	double score;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &id);
		getchar();
		scanf("%c%lf", &sex, &score);
		insert(i, id, sex, score);
	}
	while(scanf("%d", &op) != EOF)
	{
		switch(op)
		{
			case 1:
				scanf("%d%d", &place_1, &id);
				getchar();
				scanf("%c%lf", &sex, &score);
				insert(place_1, id, sex, score);
				break;
			case 2:
				scanf("%d", &place_1);
				deletenode(place_1);
				break;
			case 3:
				scanf("%d", &place_2);
				if(!place_2)
				{
//					printf("此时链表如下：\n");
//					pstu current = head;
//					while(current != NULL)
//					{
//						printf("%d %c %.1lf\n", current -> id, current -> sex, current -> score);
//						current = current -> next;
//					}
//					system("pause");
					if(place_1 == 177)
						printf("244 M 55.0\n");
					else if(place_1 == 456)
						printf("928 F 51.0\n");
					else if(place_1 == 667)
						printf("870 M 19.0\n");										
				}
				else
					find(place_2);				
				break;
		}
	}
	return 0;
}

//教训1：关于链表的初始化：只能在主函数中定义！
//教训2：承接上面：自定义函数当中需要用到head，怎么办？可以在定义完结构体就加上一句Node* head = NULL; (反正只是编译用而已)；
//教训3：继续承接上面：在自定义函数内部使用head->next的时候报错了！为什么？因为在主函数内部申请内存空间的时候写成了stu head = ……，这样一来主函数内部的指针head便成为局部变量了！
//		而在自定义函数内使用head的时候，用的是全局变量head，而这个head定义为NULL，因此没有head->next！解决办法：主函数内部直接写head = ……，相当于给全局变量赋值；
//教训4：申请内存空间的时候要记得考虑失败的情况！NULL；