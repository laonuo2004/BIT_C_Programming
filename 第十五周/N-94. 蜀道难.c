#include <stdio.h>
#define MAX 1001

static char map[MAX][MAX];
static int visited[MAX][MAX];
static char path[10000] = {'\0'};
//static int queze[10000];

int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};

typedef struct node
{
	char direction;
	int pre_x;
	int pre_y;
	int current_x;
	int current_y;
}NODE;

NODE queze[10001];
NODE *head = &queze[1];
NODE *rear = queze;

int bfs(int x, int y, int end, int n, int m);

int main()
{
	int n, m, i, j, k, t, S_x = 0, S_y = 0, ans;
	scanf("%d%d", &n, &m);
	getchar();
	for(i = 1; i <= n; i++)
		for(j = 1; j <= m+1; j++)
		{
			scanf("%c", &map[i][j]);
			if(map[i][j] == 'S')
			{
				S_x = i; S_y = j;
			}
		}
	for(i = 1; i <= 2; i++)
	{
		for(j = 1; j <= n; j++)
			for(k = 1; k <= m; k++)
				if(j == S_x && k == S_y) visited[j][k] = 1;
				else visited[j][k] = 0;
		queze[1].direction = '\0';
		queze[1].pre_x = '\0'; queze[1].pre_y = '\0';
		queze[1].current_x = S_x; queze[1].current_y = S_y;
		head = &queze[2];
		rear = &queze[1];
		ans = bfs(S_x, S_y, i+48, n, m);
		if(ans == 1)
		{
			t = 0;
			head--;
			path[++t] = head -> direction;
			NODE *temp = head;
			while(temp != &queze[1])
			{
				while(temp -> current_x == head -> pre_x && temp -> current_y == head -> pre_y)
				{
					path[++t] = temp -> direction;
					head = temp;					
				}
				temp--;
			}
			for(; t >= 1; t--) printf("%c", path[t]);
			printf("\n");
		}
	}
	return 0;
}

int bfs(int x, int y, int end, int n, int m)
{
	if(head == rear)
	{
		printf("-1\n");
		return 0;
	}
	*rear++;
	int i, nx, ny;
	for(i = 0; i < 4; i++)
	{
		nx = x+dx[i]; ny = y+dy[i];
		if(map[nx][ny] != '#' && visited[nx][ny] == 0 && nx >= 1 && nx <= n && ny >= 1 && ny <= m)
		{
			head -> pre_x = x; head -> pre_y = y;
			visited[nx][ny] = 1;
			switch(i)
			{
				case 0: head -> direction = 'D'; break;
				case 1: head -> direction = 'L'; break;
				case 2: head -> direction = 'R'; break;
				case 3: head -> direction = 'U'; break;
			}
			*head++;
			if(map[nx][ny] == end) return 1;
		}
	}
	bfs(rear -> current_x, rear -> current_y, end, n, m);
}

//教训1：if(scanf("%c", &map[i][j]) == 'S')不能这么写！if内部应加条件语句！此外scanf函数的返回值也不是输入的地址所对应的值，应当写成 (map[i][j] = getchar()) == 'S'之类的；
//教训2：遇到scanf("%c")与getchar()的时候，一定要小心误读回车！
//教训3：字符的相等判断？用ASCII码来比较！(int型)；