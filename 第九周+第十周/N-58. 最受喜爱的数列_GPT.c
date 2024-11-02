#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 数组 a 存储输入的数列
    int *a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    // prefix_ones 和 prefix_sum 分别存储 1 的数量前缀和与受喜爱程度的前缀和
    int *prefix_ones = (int*)malloc((n + 1) * sizeof(int));
    prefix_ones[0] = 0;
    
    // 用于寻找最大受喜爱程度
    int max_loved = INT_MIN;
    
    // min_loved_diff 用于记录前缀中的最小值
    int min_loved_diff = 0;
    
    for (int i = 0; i < n; i++) {
        // 更新前缀和
        prefix_ones[i+1] = prefix_ones[i] + (a[i] == 1 ? 1 : 0);
        
        // 计算当前受喜爱程度
        int current_loved = m * prefix_ones[i+1] - (i + 1);
        
        // 更新最大受喜爱程度
        if (current_loved - min_loved_diff > max_loved) {
            max_loved = current_loved - min_loved_diff;
        }
        
        // 更新最小 loved diff
        if (m * prefix_ones[i+1] - (i + 1) < min_loved_diff) {
            min_loved_diff = m * prefix_ones[i+1] - (i + 1);
        }
    }
    
    // 输出最大受喜爱程度
    printf("%d\n", max_loved);
    
    // 释放内存
    free(a);
    free(prefix_ones);
    
    return 0;
}