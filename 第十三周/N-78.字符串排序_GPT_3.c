#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 字串比较函数，用于qsort
int compare_chars(const void *a, const void *b) {
    char arg1 = *(const char *)a;
    char arg2 = *(const char *)b;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
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
        // 对每个单词的字符进行排序
        qsort(words[n], strlen(words[n]), sizeof(char), compare_chars);
        n++;
    }

    // 冒泡排序，只按照首字母从大到小排序，保持稳定性
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (words[j][0] < words[j+1][0]) {
                char *temp = words[j];
                words[j] = words[j+1];
                words[j+1] = temp;
            }
        }
    }

    // 输出排序后的结果
    for (int i = 0; i < n; i++) {
        printf("%s\n", words[i]);
        free(words[i]);  // 释放内存
    }

    return 0;
}