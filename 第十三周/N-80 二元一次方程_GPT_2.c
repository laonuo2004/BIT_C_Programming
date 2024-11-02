#include <stdio.h>

// 扩展欧几里得算法，返回gcd同时通过引用返回x和y
long long extended_gcd(long long a, long long b, long long *x, long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    long long x1, y1;
    long long gcd = extended_gcd(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}

int main() {
    long long a, b, c;
    scanf("%lld %lld %lld", &a, &b, &c);

    long long x, y;
    long long g = extended_gcd(a, b, &x, &y);

    if (c % g != 0) {
        printf("No solution\n");
    } else {
        // 计算特解
        x *= c / g;
        y *= c / g;

        // 确保x是最小正整数
        long long mod = b / g;
        if (x < 0) {
            long long adjust = (-x + mod - 1) / mod; // 计算需要增加的倍数
            x += adjust * mod;
            y -= adjust * (a / g);
        } else {
            long long adjust = (x / mod);
            x -= adjust * mod;
            y += adjust * (a / g);
        }

        // 如果调整后x仍然非正，再次调整
        if (x <= 0) {
            x += mod;
            y -= a / g;
        }

        printf("%lld %lld\n", x, y);
    }
    return 0;
}