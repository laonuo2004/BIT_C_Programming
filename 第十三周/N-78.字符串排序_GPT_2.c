#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字符串比较函数，用于qsort
int compare_chars(const void *a, const void *b) {
    char arg1 = *(const char *)a;
    char arg2 = *(const char *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// 用于稳定排序的比较函数，对首字母进行比较
int compare_strings(const void *a, const void *b) {
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;
    if (str1[0] < str2[0]) return 1;
    if (str1[0] > str2[0]) return -1;
    return 0;
}

int main() {
    char *words[10];
    char buffer[51];
    int n = 0;

    // 读取输入直到EOF
    while (scanf("%50s", buffer) != EOF) {
        words[n] = malloc(strlen(buffer) + 1);
        if (words[n] == NULL) {
            perror("Failed to allocate memory");
            return 1;
        }
        strcpy(words[n], buffer);
        n++;
    }

    // 对每个单词的字符进行排序
    for (int i = 0; i < n; i++) {
        qsort(words[i], strlen(words[i]), sizeof(char), compare_chars);
    }

    // 对单词进行稳定排序
    qsort(words, n, sizeof(char *), compare_strings);

    // 输出排序后的结果
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        free(words[i]);  // 释放内存
    }

    return 0;
}