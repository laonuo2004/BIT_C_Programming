#include <stdio.h>

void move(int n, int opt) {
    if (n == 0) return;  // 如果没有环需要操作，直接返回
    if (opt == 0) {
        // 取下第n个环，必须先确保第n-1个环在棒上，小于n-1的都不在棒上
        move(n - 1, 1);  // 确保第n-1个环在棒上
        for (int i = 1; i < n - 1; i++) {
            move(i, 0);  // 确保所有小于n-1的环不在棒上
        }
        printf("%d ", n);  // 取下第n个环
        move(n - 1, 0);  // 取下第n-1个环，以便继续后续操作
    } else {
        // 放上第n个环，同样需要先确保第n-1个环在棒上，小于n-1的都不在棒上
        move(n - 1, 1);
        for (int i = 1; i < n - 1; i++) {
            move(i, 0);
        }
        printf("%d ", n);  // 放上第n个环
        for (int i = 1; i < n - 1; i++) {
            move(i, 1);  // 重放所有小于n-1的环
        }
    }
}

int solve(int pos, int opt) {
    move(pos, opt);  // 调用move函数开始取下或放上操作
    return 0;
}

int main() {
    int n;
    scanf("%d", &n);
    solve(n, 0);
    return 0;
}