#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int n, l, r;
        scanf("%d %d %d", &n, &l, &r);
        
        int t1 = 0, t2 = 0, t3 = 0; // t1:三角形数量, t2:等腰三角形数量, t3:直角三角形数量
        
        for (int a = l; a <= r; a++) {
            for (int b = a; b <= r; b++) {
                int c = n - a - b;
                if (b <= c && c <= r) {
                    if (a + b > c && a + c > b && b + c > a) { // 三角形条件
                        t1++; // 可形成三角形
                        
                        if (a == b || b == c || a == c) {
                            t2++; // 等腰三角形
                        }
                        
                        if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a)) {
                            t3++; // 直角三角形
                        }
                    }
                }
            }
        }
        
        printf("%d %d %d\n", t1, t2, t3);
    }
    return 0;
}