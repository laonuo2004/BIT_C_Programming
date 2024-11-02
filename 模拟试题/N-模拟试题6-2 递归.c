/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  

int f(int n,int m);  

int main()  
{  
    int n,m;  
    scanf("%d%d",&n,&m);  
    printf("%d\n",f(n,m));  
//    system("pause");  
	return 0;
}  
/* This is an example for list. Please programme your code like it.  
int f(int n, int m) 
{ 
    ...... 
}  
*/  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 

int f(int n, int m)
{
	if(n > m && m > 0 && n < 4)
		return 1;
	else if(n > m && m > 4 && !(m&1))
		return f(n, m-1)+f(n, m-3);
	else if(n > m && m > 4 && m&1)
		return f(n, m-2)+f(n-4, m);
	else
		return -1;
}

//教训1：注意乐学上这种有预置代码的题目：只需要把自己的函数交上去就可以了！不需要把预置代码重复提交！否则会编译失败……