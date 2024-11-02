#include <stdio.h>
#include <math.h>

int main()
{
	int s[20001] = {0};
	s[1] = 1;
	s[2] = 0;
	for(int i = 2; i * i <= 20000; i++)
	{
		if(!s[i])
		{
			for(int j = i*i; j <= 20000; j+=i)
			{
				s[j] = 1;
			}	
		}
	}
	int temp, ch;
	do
	{
		scanf("%d", &temp);
		ch = getchar();
		int root = (int)sqrt(temp);
		if((!s[root]) && (root*root==temp)) printf("TQL!\n");
		else printf("TCL!\n");
	}while(ch != '\n');
	return 0;
}

//教训1：数组开上万的时候debug就出不来结果了，不过还是照样可以算
//教训2：埃氏筛的使用
//教训3：不知道输入次数的时候可以用 while(scanf()!=EOF) 来避免超时，或者在输入后面加 ch = getchar() 然后判断是否是回车；
//教训4：埃氏筛的1和2需要手动初始化！1不是质数，2是质数。
//教训5：宏定义用于反复出现的数
//教训6：bool类型的使用方法
//教训7：要多写一句 int root = (int)sqrt(temp)，不要直接把 (int)sqrt(temp) 放到语句当中去用！可能是运算优先级之类的问题？也有可能是乐学编译器的问题。
//教训8：判断语句不用 i <= sqrt(max) 而用 i*i <= max， 不用担心整数开平方的问题

//GPT给出的正确代码：
//#include <stdio.h>
//#include <math.h>
//#include <stdbool.h>
//
//#define MAX 20001  // 可调整为更高的值以提供更大范围的质数检查
//
//int main() {
//    bool is_prime[MAX] = {false};
//    for (int i = 2; i < MAX; i++) {
//        is_prime[i] = true;
//    }
//    
//    for (int i = 2; i * i < MAX; i++) {
//        if (is_prime[i]) {
//            for (int j = i * i; j < MAX; j += i) {
//                is_prime[j] = false;
//            }
//        }
//    }
//    
//    int n;
//    while (scanf("%d", &n) == 1) {
//        int root = (int)sqrt(n);
//        if (root * root == n && is_prime[root]) {
//            printf("TQL!\n");
//        } else {
//            printf("TCL!\n");
//        }
//    }
//    
//    return 0;
//}