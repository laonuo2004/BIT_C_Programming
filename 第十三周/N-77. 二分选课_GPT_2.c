#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int id;  // 课程编号
    int slots;        // 剩余名额
} Course;

// 根据课程编号比较两个课程的函数，用于 qsort 和 bsearch
int compareCourse(const void *a, const void *b) {
    Course *courseA = (Course *)a;
    Course *courseB = (Course *)b;
    return (courseA->id > courseB->id) - (courseA->id < courseB->id);
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    Course *courses = malloc(n * sizeof(Course));  // 动态分配课程数组

    // 读取课程信息
    for (int i = 0; i < n; i++) {
        scanf("%u %d", &courses[i].id, &courses[i].slots);
    }

    // 对课程数组排序，以便使用二分查找
    qsort(courses, n, sizeof(Course), compareCourse);

    // 处理客户查询
    unsigned int queryId;
    int querySlots;
    for (int i = 0; i < t; i++) {
        scanf("%u %d", &queryId, &querySlots);
        Course key = {queryId, 0};
        Course *found = (Course *)bsearch(&key, courses, n, sizeof(Course), compareCourse);
        
        if (!found) {
            printf("ERR\n");
        } else if (found->slots < querySlots) {
            printf("Failed\n");
        } else {
            found->slots -= querySlots;  // 更新名额
            printf("Succeeded\n");
        }
    }

    free(courses);  // 释放分配的内存
    return 0;
}