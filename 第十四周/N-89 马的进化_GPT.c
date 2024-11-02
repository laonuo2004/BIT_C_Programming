#include<stdio.h>

int m, n, t, p, q, num;

void dfs(int a, int b) {
    if (a == 0 && b == m) {  // 检查是否到达右上角（0, m）
        t++;  // 找到一条路径，增加计数
        return;
    }

    // 向右上移动：向右两格，向上一格
    if (b + 2 <= m && a - 1 >= 0) {
        dfs(a - 1, b + 2);
    }

    // 向右下移动：向右两格，向下一格
    if (b + 2 <= m && a + 1 <= n) {
        dfs(a + 1, b + 2);
    }
}

int main() {
    scanf("%d", &num);
    for (int i = 1; i <= num; i++) {
        t = 0;  // 初始化路径计数器
        scanf("%d %d %d %d", &n, &m, &p, &q);
        dfs(p, q);  // 开始从(p, q)位置深度优先搜索
        printf("%d\n", t);  // 输出找到的路径数
    }
    return 0;
}