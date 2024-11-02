#include <stdio.h>
#include <string.h>

int main() {
    char S[101], T[101];
    scanf("%s", S);
    scanf("%s", T);
    
    int lenS = strlen(S), lenT = strlen(T);
    
    // 如果T比S长，则不可能成为子串
    if (lenT > lenS) {
        printf("-1\n");
        return 0;
    }
    
    int min_changes = 1000000;  // 初始化为一个大数，用于寻找最小值
    
    // 遍历S中所有可能的起始位置
    for (int i = 0; i <= lenS - lenT; i++) {
        int changes = 0;
        // 比较S的子串与T
        for (int j = 0; j < lenT; j++) {
            if (S[i + j] != T[j]) {
                changes++;  // 计算需要更改的字符数
            }
        }
        // 更新最小更改次数
        if (changes < min_changes) {
            min_changes = changes;
        }
    }
    
    // 输出最小操作次数
    printf("%d\n", min_changes);
    return 0;
}