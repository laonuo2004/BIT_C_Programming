#include <stdio.h>
#include <string.h>

#define MAX_N 1001

int n, m;
char grid[MAX_N][MAX_N];
int visited[MAX_N][MAX_N];
int dx[] = {1, 0, -1, 0}; // Down, Right, Up, Left
int dy[] = {0, 1, 0, -1}; // Down, Right, Up, Left
char dir[] = "DRUL"; // Corresponding directions as characters

typedef struct {
    int x, y, step;  // Add step index to keep the current length of the path
    char path[MAX_N * MAX_N];
} QueueItem;

void bfs(int startx, int starty, char target, char* output) {
    int front = 0, rear = 0;
    QueueItem queue[MAX_N * MAX_N];
    memset(visited, 0, sizeof(visited));
    queue[rear++] = (QueueItem){startx, starty, 0, ""};
    visited[startx][starty] = 1;

    while (front < rear) {
        QueueItem current = queue[front++];

        if (grid[current.x][current.y] == target) {
            strcpy(output, current.path);
            return;  // Return as soon as the first path to the target is found
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i], ny = current.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] != '#') {
                visited[nx][ny] = 1;
                queue[rear].x = nx;
                queue[rear].y = ny;
                queue[rear].step = current.step + 1;
                strcpy(queue[rear].path, current.path);
                queue[rear].path[current.step] = dir[i];
                queue[rear].path[current.step + 1] = '\0';
                rear++;
            }
        }
    }

    strcpy(output, "-1");  // If no path found
}

int main() {
    scanf("%d %d", &n, &m);
    int startx = -1, starty = -1;
    char output1[MAX_N * MAX_N] = "", output2[MAX_N * MAX_N] = "";

    for (int i = 0; i < n; i++) {
        scanf("%s", grid[i]);
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'S') {
                startx = i;
                starty = j;
            }
        }
    }

    bfs(startx, starty, '1', output1);
    bfs(startx, starty, '2', output2);

    printf("%s\n", output1);
    printf("%s\n", output2);

    return 0;
}