#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int romanToInt(char *s) {
    int nums[256] = {0};
    nums['I'] = 1; nums['V'] = 5; nums['X'] = 10;
    nums['L'] = 50; nums['C'] = 100; nums['D'] = 500; nums['M'] = 1000;

    int result = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (nums[s[i]] < nums[s[i + 1]]) {
            result -= nums[s[i]];
        } else {
            result += nums[s[i]];
        }
    }
    return result;
}

int sumDigitsUntilOne(int num) {
    while (num >= 10) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        num = sum;
    }
    return num;
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int getCaesarKey(int numbers[], int n, int seed) {
    qsort(numbers, n, sizeof(int), compare);
    return numbers[seed - 1] % 26;  // 返回偏移量
}

void caesarCipher(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
    }
}

int main() {
    char roman[100], inputText[1024];
    int numbers[25], seed, key;

    // 输入处理
    fgets(roman, sizeof(roman), stdin);
    roman[strcspn(roman, "\n")] = 0;  // 去掉换行符

    for (int i = 0; i < 25; i++) {
        scanf("%d", &numbers[i]);
    }
    getchar();  // 消费掉数字后的换行符

    fgets(inputText, sizeof(inputText), stdin);
    inputText[strcspn(inputText, "\n")] = 0;  // 去掉换行符

    // 处理罗马数字
    int num = romanToInt(roman);
    seed = sumDigitsUntilOne(num);

    // 获取密钥
    key = getCaesarKey(numbers, 25, seed);

    // 加密文本
    caesarCipher(inputText, key);

    // 输出结果
    printf("%s\n", inputText);
    return 0;
}