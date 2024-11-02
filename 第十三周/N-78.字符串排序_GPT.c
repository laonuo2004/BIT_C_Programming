#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 比较函数，用于根据字符串的首字符降序排序
int compare(const void *a, const void *b) {
    char *strA = *(char**)a;
    char *strB = *(char**)b;
    return (strB[0] - strA[0]);
}

int main() {
    char **words = malloc(n * sizeof(char*));  // 动态分配指针数组空间

    for (int i = 0; i < n; i++) {
        words[i] = malloc(51 * sizeof(char));  // 为每个单词分配空间
        scanf("%s", words[i]);  // 读取单词
        int len = strlen(words[i]);

        // 对单词内的字符排序
        qsort(words[i], len, sizeof(char), (int (*)(const void*, const void*)) strcmp);
    }

    // 根据首字符对单词数组进行降序排序
    qsort(words, n, sizeof(char*), compare);

    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);  // 输出排序后的单词
        free(words[i]);  // 释放单词占用的内存
    }
    free(words);  // 释放指针数组空间

    return 0;
}