#include <stdio.h>

void swap(void *a, void *b) {
	char temp;
	while(*(char *)a != '\0' || *(char *)b != '\0')
	{
		temp = *(char *)a;
		*(char *)a = *(char *)b;
		*(char *)b = temp;
		*(char *)a++; *(char *)b++;
	}
}

int main() {
    char a[10001] = {'\0'}, b[10001] = {'\0'};
    scanf("%s%s", &a, &b);
    swap(&a, &b);
    printf("%s\n%s\n", a, b);
    return 0;
}

//教训1：定义了 void 指针之后，在使用前都要记得强转类型！(没法对 void 类型指针进行操作啊！)；