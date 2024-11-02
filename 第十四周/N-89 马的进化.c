/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include<stdio.h>  
  
int m,n,t,p,q,num;  
  
void dfs(int a,int b);  
int main(){  
    scanf("%d",&num);  
    for(int i=1;i<=num;i++){  
        t=0;  
        scanf("%d%d%d%d",&n,&m,&p,&q);  
        dfs(p,q);  
        printf("%d\n",t);  
    }  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

void dfs(int a, int b) 
{
    if (a == n && b == m) {
        t++;
        return;
    }
    if (a < n && b + 2 <= m) {
//        printf("%d %d\n", a, b);
		dfs(a + 1, b + 2);
    }
    if (a + 2 <= n && b + 1 <= m) {
//        printf("%d %d\n", a, b);
		dfs(a + 2, b + 1);
    }
    if (a > 0 && b + 2 <= m) {
//        printf("%d %d\n", a, b);
		dfs(a - 1, b + 2);
    }
    if (a - 2 >= 0 && b + 1 <= m) {
//        printf("%d %d\n", a, b);
		dfs(a - 2, b + 1);
    }
}