/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include<stdio.h>   
int n,m,x,y,a[401][401];  
void dfs(int x,int y,int step);  
int main(){  
    scanf("%d%d",&n,&m);  
    for(int i=0;i<401;i++)  
    for(int j=0;j<401;j++)  
    a[i][j]=-1;//这里初始化-1 表示为无法到达   
    dfs(1,1,0);  
    for(int i=1;i<=n;i++){  
    for(int j=1;j<=m;j++)  
    printf("%5d",a[i][j]);  
    printf("\n");  
    }  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */ 

void dfs(int x,int y,int step)
{
	if(x<1 || y<1 || x>n || y>m)
		return;
	if(a[x][y] == -1 || a[x][y] > step)
		a[x][y] = step;
	else
		return;
//	for(int i=1;i<=n;i++){  
//    for(int j=1;j<=m;j++)  
//    printf("%d ",a[i][j]);  
//    printf("\n"); 
//}
	dfs(x+2, y+1, step+1);
	dfs(x+1, y+2, step+1);
	dfs(x-1, y+2, step+1);
	dfs(x-2, y+1, step+1);
	dfs(x+2, y-1, step+1);
	dfs(x+1, y-2, step+1);
	dfs(x-1, y-2, step+1);
	dfs(x-2, y-1, step+1);
}