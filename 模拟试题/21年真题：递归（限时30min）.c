/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
void PrintChar(int number,char c){
    int i;
	for ( i=0 ; i< number; i++)
        printf("%c",c);
}

// 递归函数-----------需要补全
char RecursionFunction(int n, char c);

int main(){
    char c; int n;
    scanf("%d %c",&n,&c);
    RecursionFunction(n,c);
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

char RecursionFunction(int n, char c)
{
	if(n > 0)
		PrintChar(n, c);
	if(n > 0 && c == '#')
		return RecursionFunction(n-1, '*');
	else if(n > 0 && c == '*')
		return RecursionFunction(n+2, '?');
	else if(n > 0 && c == '?')
		return RecursionFunction(n+3, '+');
	else if(n > 0 && c == '+')
		return RecursionFunction(n-6, '#');				
	else
		printf("\nRecursionFunction has been over !\n");
}