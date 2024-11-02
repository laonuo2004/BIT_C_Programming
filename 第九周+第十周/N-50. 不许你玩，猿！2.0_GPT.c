#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    
    int swapCount = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            int cycle_size = 0;
            int x = i;
            while (!visited[x]) {
                visited[x] = 1;
                cycle_size++;
                x = a[x] - 1;  // 转移到下一个索引
            }
            if (cycle_size > 1) {
                swapCount += cycle_size - 1;
            }
        }
    }
    
    printf("%d\n", swapCount);
    return 0;
}