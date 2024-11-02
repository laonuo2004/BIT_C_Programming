#include <stdio.h>
#include <string.h>

void change(char *p, int *p_)
{
	if(*p >= '0' && *p <= '9')
		*p_ = *p-48;
	else
		*p_ = *p-87;
}

int main()
{
	int n;
	scanf("%d", &n);
	char temp[9] = {'\0'};
	int temp_[9] = {0};
	unsigned long long a[101] = {0};
	int b[101] = {0};
	char *p = NULL;
	int *p_ = NULL;
	int counter = 0;
	unsigned long long times = 1;
	for(int i = 1; i <= n; i++)
	{
		int temp_[9] = {0};
		counter = 0;
		scanf("%s", &temp);
		scanf("%d", &b[0]);
		a[0] = 0;
		p = temp; p_ = &temp_[8];
		while(*p != '\0')
		{
			change(p, p_);
			*p++; *p_--; counter++;
		}
		for(int j = 8; j >= 1; j--)
		{
			times = 1;
			for(int k = 1; k <= counter-9+j; k++)
			{
				times *= b[0];
			}
			a[0] += temp_[j]*times;
		}
		for(int j = n; j >= 1; j--)
		{
			b[j+1] = b[j];
			a[j+1] = a[j];
			if(b[j-1] >= b[0])
			{
				b[j] = b[0];
				a[j] = a[0];
				if(b[j] != b[j-1])
					break;
				else
				{
					for(int k = j; k >= 1; k--)
					{
						if(a[k-1] >= a[0] || b[k-1] != b[0])
						{
							a[k] = a[0];
							break;
						}
						a[k] = a[k-1];
					}
				}
				break;
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		printf("%llu %d\n", a[i], b[i]);
	}
	return 0;
}

//教训1：对于字符串，需要多开一个格子用来存放 '\0'；
//教训2：指针初始化的习惯！
//教训3：指针的赋值：记得加 &！
//教训4：指针遍历字符串：while(*p != '\0') 与 *p++；
//教训5：指针传入函数？同理只用加 p表示变量名称；
//教训6：使用一维指针指向一维数组，直接 p = temp 即可；使用一维指针指向二维数组，需要强转类型 p = (char *)temp，这样一来就可以遍历二维数组中的每一个元素；
//       但若想要逐行读取元素，则需要定义数组指针，例如本题定义 a[101][9]，可以这样逐行输出：
//			char (*p)[9];
//    			p=a; //可以直接赋值，不会有错
//    			for( i=1;i<=100;i++ )
//        			printf("%s\n", p++ ); //输出一行，并将p指向下一行
//		这样一来就能按行输出字符串了；
//教训7：原先把 *p++ 与 *p_--写到 change 函数中，结果写出了死循环……注意：函数中的指针遍历不可取！除非把变化过后的指针再传出到主函数。(不过多次一举，不如直接在主函数遍历)；
//教训8：每次循环都要记得重新初始化一遍值！例如 a[0]、times 这些
//教训9：双层插值排序法：参考数组 a 的排序！注意三点：1、先把值放进 a[j] 再说；2、注意 k 从 j 开始，而非 j-1，否则少比较了刚开始的两者。同时要求为 a[k] = a[k-1]，避免多移位到 j+1；
//						3、a[k-1]是和 a[0] 比，不是和 a[k] 比！
//教训10：注意数据范围，a、times 需要 long long，对应输出格式 %llu；
//教训11：计算每一位所贡献的数时，由于是从后往前塞的，所以要注意好k的循环条件！此处为 counter-9+j 而非 8-j；
//教训12：还忘记了清空 temp_！于是当后一个数位数比前一个数小的时候，后一个数就会算错；