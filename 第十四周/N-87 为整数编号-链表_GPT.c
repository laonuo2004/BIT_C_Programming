/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
struct nn  
{  int no;     
   int num;     
};  
  
typedef struct nn DATA;  
  
int number( char * str, DATA []);  
  
int main( )  
{     
   DATA b[100];    
   char sa[500];    
   int i, n;    
   gets( sa );   
   n = number( sa, b );   
   for ( i=0; i<n; i++ )   
       printf("%d %d\n", b[i].num, b[i].no );   
   return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

int compare(const void *a, const void *b)
{
    DATA *dataA = *(DATA **)a;
    DATA *dataB = *(DATA **)b;
    return dataA->num - dataB->num;
}

int number(char *str, DATA a[])
{
    int count = 0;
    char *token = strtok(str, " ");
    while (token != NULL && count < 100)
    {
        a[count].num = atoi(token);
        a[count].no = 0;
        count++;
        token = strtok(NULL, " ");
    }

    DATA *sorted[count];
    for (int i = 0; i < count; i++)
    {
        sorted[i] = &a[i];
    }

    qsort(sorted, count, sizeof(DATA *), compare);

    for (int i = 0; i < count; i++)
    {
        sorted[i]->no = i + 1;
    }

    return count;
}