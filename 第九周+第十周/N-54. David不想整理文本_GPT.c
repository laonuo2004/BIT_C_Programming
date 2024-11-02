#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char input[256];
    fgets(input, 256, stdin);  // 使用fgets而不是gets，因为gets已被弃用

    char output[256];
    int n = strlen(input);
    int index = 0, first = 1;

    for (int i = 0; i < n; i++) {
        // 跳过首部多余空格
        if (first && input[i] == ' ') continue;

        // 处理每个句子的首字母大写
        if (first && isalpha(input[i])) {
            output[index++] = toupper(input[i]);
            first = 0;
            continue;
        }

        // 以小写形式处理其他字母
        if (isalpha(input[i])) {
            output[index++] = tolower(input[i]);
        } else if (input[i] == '.' || input[i] == ',') {
            // 处理标点符号：确保前面没有多余空格，标点后添加一个空格
            if (index > 0 && output[index - 1] == ' ') {
                output[index - 1] = input[i];
            } else {
                output[index++] = input[i];
            }
            if (i + 1 < n && input[i + 1] != ' ') {
                output[index++] = ' ';
            }
            first = (input[i] == '.') ? 1 : 0;  // 句点后的首字母需要大写
        } else if (input[i] == ' ') {
            // 确保单词后只有一个空格
            if (index > 0 && output[index - 1] != ' ' && output[index - 1] != '.' && output[index - 1] != ',') {
                output[index++] = ' ';
            }
        }
    }

    // 删除尾部多余空格
    if (index > 0 && output[index - 1] == ' ') index--;
    output[index] = '\0';  // 确保字符串正确终结

    printf("%s\n", output);
    return 0;
}