#include <stdio.h>
#include <string.h>

int main() {
    char s1[51], s2[51], s3[51];
    scanf("%s", s1);
    scanf("%s", s2);
    scanf("%s", s3);
    
    char *min_str = s1;
    // 比较s1和s2
    if (strlen(s2) < strlen(min_str) || (strlen(s2) == strlen(min_str) && strcmp(s2, min_str) > 0)) {
        min_str = s2;
    }
    // 比较当前最小的字符串和s3
    if (strlen(s3) < strlen(min_str) || (strlen(s3) == strlen(min_str) && strcmp(s3, min_str) > 0)) {
        min_str = s3;
    }
    
    printf("%s\n", min_str);
    return 0;
}