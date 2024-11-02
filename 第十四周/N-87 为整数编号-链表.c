/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
struct nn  
{  int no;     
   int num;     
};  
  
typedef struct nn DATA;  
  
int number( char * , DATA []);  
  
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
  
/* Here is waiting for you  
  int number( char * str, DATA a[] ) 
  { 
      .... 
  } 
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */