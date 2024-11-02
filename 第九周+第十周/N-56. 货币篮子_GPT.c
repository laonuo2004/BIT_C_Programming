#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int n;
    double p, x;
    char s[4];
    
    // 读取输入：n 年数，p 通胀率
    scanf("%d %lf", &n, &p);
    // 读取输入：x 人民币价值
    scanf("%lf", &x);
    // 读取输入：s 目标货币
    scanf("%s", s);
    
    // 计算n年前的人民币价值
    double value_in_past = x / pow(1.0 + p, n);
    
    double result;
    // 根据目标货币进行换算
    if (strcmp(s, "USD") == 0) {
        result = value_in_past / 6.48;
    } else if (strcmp(s, "JPY") == 0) {
        result = value_in_past / 0.061;
    } else if (strcmp(s, "EUR") == 0) {
        result = value_in_past / 7.82;
    } else if (strcmp(s, "GBP") == 0) {
        result = value_in_past / 9.02;
    } else if (strcmp(s, "CNY") == 0) {
        result = value_in_past; // 无需换算
    } else {
        // 若输入了未定义的货币单位，默认为CNY处理
        result = value_in_past;
    }
    
    // 输出结果，保留两位小数
    printf("%.2f\n", result);
    
    return 0;
}