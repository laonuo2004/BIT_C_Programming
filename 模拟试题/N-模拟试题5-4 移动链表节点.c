/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct numLink  
{  
    int no;  
    struct numLink *next;  
}NODE, *PNODE;  
  
void movenode( NODE *head);  
  
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
    int n;  
    NODE *head=NULL, *q=NULL;  
    scanf("%d",&n);  
  
    head = (NODE *)malloc(sizeof(NODE));  
    head->no = -1;  
    head->next = NULL;  
  
    SetLink( head, n );  
    movenode( head );  
  
    q = head;  
    while (q->next){  
        printf("%d ",q->next->no);  
        q = q->next;  
    }   
    printf("\n");  
      
    system("pause");  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 

void movenode( NODE *head)
{
	if(head -> next == NULL)
		return;
	NODE *firstodd = head -> next;
	if(firstodd -> next == NULL)
		return;
	NODE *firsteven = firstodd -> next;
	NODE *odd = firstodd, *even = firsteven;
	while(odd -> next != NULL && even -> next != NULL)
	{
		odd -> next = even -> next;
		odd = odd -> next;
		even -> next = odd -> next;
		even = even -> next; 
	}
	odd -> next = firsteven;
	return;
}