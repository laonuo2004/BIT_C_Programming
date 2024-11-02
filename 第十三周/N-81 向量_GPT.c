#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;  // 当前数组的大小
    int count; // 当前数组中元素的数量
} Vector;

// 初始化向量
void initVector(Vector *v, int initial_size, int initial_value) {
    v->array = (int *)malloc(initial_size * sizeof(int));
    v->array[0] = initial_value;
    v->size = initial_size;
    v->count = 1;
}

// 添加元素到向量
void addToVector(Vector *v, int value) {
    if (v->count == v->size) {
        // 如果当前元素数量达到数组大小，进行扩容
        v->size *= 2; // 双倍扩容
        v->array = (int *)realloc(v->array, v->size * sizeof(int));
    }
    v->array[v->count] = value;
    v->count++;
}

// 获取向量的特定位置元素
int getElement(Vector *v, int index) {
    if (index < 1 || index > v->count) {
        return -1; // 错误处理
    }
    return v->array[index - 1]; // 转换为 0-based 索引
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    Vector *vectors = (Vector *)malloc((N + 1) * sizeof(Vector));
    for (int i = 1; i <= N; i++) {
        initVector(&vectors[i], 2, i); // 初始大小设置为2
    }

    for (int i = 0; i < M; i++) {
        int vi, ai, pi;
        scanf("%d %d %d", &vi, &ai, &pi);
        addToVector(&vectors[vi], ai);
        printf("%d\n", getElement(&vectors[vi], pi));
    }

    // 释放所有向量的内存
    for (int i = 1; i <= N; i++) {
        free(vectors[i].array);
    }
    free(vectors);

    return 0;
}