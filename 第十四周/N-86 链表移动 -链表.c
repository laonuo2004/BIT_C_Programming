/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE;  
  
NODE *monenode( NODE *head, int m );  
  
void SetLink( NODE *h, int n )  
{  
    NODE *p=NULL, *q=NULL;  
    int i;  
    for( i=0; i<n; i++)  
    {  
        p = (NODE *)malloc(sizeof(NODE));  
        p->no = i+1;  
        p->next = NULL;  
        if( h->next == NULL )  
        {  
            h->next = p;  
            q = p;  
        }  
        else  
        {  
            q->next = p;  
            q = q->next;  
        }  
    }  
    return;  
}  
  
int main( )  
{  
    int n,m;  
    NODE *head=NULL, *q=NULL;  
    scanf("%d%d",&n,&m);  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head, n );  
  
    q = monenode( head, m );  
  
    do  
    {  
        printf("%d ",q->next->no);  
        q = q->next;  
    }while( q->next != NULL );   
    printf("\n");  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

NODE *monenode( NODE *head, int m )
{
	if(head == NULL || head -> next == NULL || m <= 0) // 排除空链表与 m 不符合的情况
		return head; 
		
	NODE *firstnode = head -> next; // 第一个实际节点
	NODE *lastnode = head;
	while(lastnode -> next != NULL)
		lastnode = lastnode -> next; // 最后一个节点
		
	NODE *current = head;
	for(int i = 1; i <= m; i++) // 找到截断处前的节点
	{
		current = current -> next;
		if(current -> next == NULL) // 排除 m 大于节点数量的情况
			return head;
	}
		
	head -> next = current -> next; // 让头结点指向截断处后的节点
	current -> next = NULL; // 让截断处前节点的 next 指针指向空指针
	lastnode -> next = firstnode; // 将原链表的最后一个节点指向原链表的第一个节点
	
	return head;
}

//教训1：head -> next都不用加*！
//教训2：注意特殊情况！如果空链表？m过小或超出了范围？