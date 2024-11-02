#include <stdio.h>
#include <string.h>

// 通用的 swap 函数，使用 void 指针和 size_t 来处理不同数据类型
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

int main() {
    int a, b;  // 假设数据类型为 int，可以修改为其他类型如 double 等

    // 读入两个整数
    scanf("%d %d", &a, &b);

    // 调用 swap 函数交换两个整数
    swap(&a, &b, sizeof(a));

    // 输出交换后的结果
    printf("%d\n%d\n", a, b);

    return 0;
}