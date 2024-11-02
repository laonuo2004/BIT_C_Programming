#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y, index;
} Point;

int compare(const void *a, const void *b) {
    const Point *p1 = (const Point *)a;
    const Point *p2 = (const Point *)b;
    
    // 使用交叉乘积判断极角大小
    long long cross_product = (long long)p1->x * p2->y - (long long)p1->y * p2->x;
    
    if (cross_product > 0) return -1;  // p1 的极角小于 p2 的极角
    if (cross_product < 0) return 1;   // p1 的极角大于 p2 的极角
    
//    // 极角相同，比较 x 坐标（或 y 坐标）
//    return p1->x - p2->x;
	return p1 -> index - p2 -> index;
}

int main() {
    int n;
    scanf("%d", &n);
    Point points[3001];
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].index = i + 1;
    }
    
    qsort(points, n, sizeof(Point), compare);
    
    for (int i = 0; i < n; i++) {
        printf("%d\n", points[i].index);
//		printf("第%d个点的信息：\n编号：%d\nx值：%d\ny值：%d\n", i+1, points[i].index, points[i].x, points[i].y);
    }

//	for(int i = 0 ; i < n; ++i)
//		for(int j = 0; j < n; ++j)
//			if(points[j].index == i+1)
//			{
//				printf("%d\n", j+1);
//				break;
//			}	
    return 0;
}
