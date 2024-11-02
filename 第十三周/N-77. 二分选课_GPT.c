#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 300
#define MAX_ID 4294967295

// 课程结构体定义
typedef struct {
    unsigned int id;  // 课程编号
    int slots;        // 剩余名额
} Course;

Course courses[MAX_COURSES];  // 存储所有课程信息
int courseCount = 0;          // 实际课程数目

// 哈希表，为了简化问题，我们直接使用课程编号的哈希
Course* hashTable[MAX_ID];

// 哈希函数
unsigned int hash(unsigned int id) {
    return id % MAX_ID;
}

// 初始化哈希表
void initHashTable() {
    for (unsigned int i = 0; i < MAX_ID; i++) {
        hashTable[i] = NULL;
    }
}

// 将课程添加到哈希表中
void addCourseToHashTable(Course *course) {
    unsigned int index = hash(course->id);
    hashTable[index] = course;
}

// 查找课程
Course* findCourse(unsigned int id) {
    unsigned int index = hash(id);
    return hashTable[index];  // 简化处理，假设哈希冲突概率低
}

int main() {
    int n, t;
    scanf("%d %d", &n, &t);

    initHashTable();

    // 读取课程信息
    for (int i = 0; i < n; i++) {
        scanf("%u %d", &courses[i].id, &courses[i].slots);
        addCourseToHashTable(&courses[i]);
    }

    // 处理客户访问
    unsigned int queryId;
    int querySlots;
    for (int i = 0; i < t; i++) {
        scanf("%u %d", &queryId, &querySlots);
        Course *course = findCourse(queryId);
        if (!course) {
            printf("ERR\n");
        } else if (course->slots < querySlots) {
            printf("Failed\n");
        } else {
            course->slots -= querySlots;  // 更新名额
            printf("Succeeded\n");
        }
    }

    return 0;
}