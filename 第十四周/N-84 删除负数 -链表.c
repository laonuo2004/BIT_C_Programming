/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
    
struct node    
{  
    int data;    
    struct node * next;    
};    
    
typedef struct node NODE;   
typedef struct node * PNODE;  
   
PNODE constructlist( PNODE head, int num );  
void outlist( PNODE head );  
void deleteneg( PNODE head );   
    
int main ( )    
{   int num=1;    
    PNODE head;    
    
    head = (PNODE)malloc( sizeof(NODE) );    
    head->next = NULL;    
    head->data = -1;    
    
    while ( num!=0 )    
    {   scanf("%d", &num);    
        if ( num!=0 )    
           constructlist (head, num);    
    }    
    deleteneg( head );  
    outlist( head );    
    return 0;    
}    
    
PNODE constructlist( PNODE head, int num )  
{   PNODE p;  
    p = (PNODE)malloc( sizeof(NODE) );   
    p->data = num;  
    p->next = head->next;   
    head->next = p;  
    return head;  
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
void deleteneg( PNODE head )  
{    
}  
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

void deleteneg( PNODE head )  
{
	PNODE temp;
	PNODE current = head;
	while(current -> next != NULL)
	{
		if((current -> next) -> data < 0)
		{
			temp = current -> next;
			current -> next = temp -> next;
			free(temp);
		}
		else
			current = current -> next;
	}
}

//教训1：还是习惯写 temp++/current++……注意！链表要遍历的话用 temp = temp -> next！
//教训2：一些特殊情况没有考虑：第一个就是负数？最后一个是负数？
//教训3：为什么从头结点出发，第一个是负数的时候会报错？！
//教训4：链表删除要一个一个地删！同时记得释放内存！
//教训5：可以 current -> next -> data，不用括号，因为是左结合；
//教训6：本题实质上就是遍历链表，遇到负数节点就跳过+释放空间即可；