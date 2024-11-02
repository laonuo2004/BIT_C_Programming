/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include "stdio.h"
#include "stdlib.h"

struct node
{
    int data;
    struct node * next;
};

typedef struct node NODE;
typedef struct node * PNODE;

void outlist( PNODE );
void deletenode(NODE *head, int num);

int main ( )
{
    int num=1;
    PNODE head, p, newnode;
    int index = -1, value = 0;

    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    p= head;
    while ( num!=0 )
    {
        scanf("%d", &num);
        if ( num!=0 )
        {
            newnode = (PNODE)malloc( sizeof(NODE) );
            newnode->next= NULL;
            newnode->data  = num;

            p->next = newnode;
            p = p->next;
        }
    }

    scanf("%d", &value);

    deletenode(head, value);
    outlist(head);
    system("pause");
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d\n", p->data);
        p = p->next;
    }
}

/* This is an example for list. Please programme your code like it.
void deletenode(NODE *head, int num)
{
    ......
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void deletenode(NODE *head, int num)
{
    PNODE current = head, deleteNODE;
    int i;
    for(i = 1; i < num; i++)
    {
    	current = current -> next;
    	if(current -> next == NULL)
    	{
    		printf("X is too large!\n");
    		exit(0);
		}
	}
    deleteNODE = current -> next;
    current -> next = deleteNODE -> next;
    free(deleteNODE);
    return;
}

//教训1：这类链表的题目，经常需要特判：给出的数是否符合链表长度！（很多时候可能会超出链表长度，需要额外注意！）；
//教训2：关于函数中return与exit(0)的使用区别：return可以终止这个函数，而exit(0)会直接终止整个程序！
//		这在本题当中x超长的时候可以体现出来：在printf("X is too large!\n");之后如果使用return的话，程序还是会输出链表的值，而这是我们所不希望看到的。此时使用exit(0)就能避免这个问题；