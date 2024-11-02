#include <stdio.h>

int main()
{
	char filename[6] = {'\0'}, c, s[20];
	int n, i;
	scanf("%s%d", filename, &n);
	filename[5] = '\0';
	FILE *fp;
	if((fp = fopen(filename, "r")) == NULL)
	{
		printf("File Name Error.\n");
		return 0;
	}
//	for(i = 1; i <= n - 1; i++)
//	{
//		while((c = fgetc(fp)) != '\n')
//			if(c == EOF)
//			{
//				printf("Line No Error.\n");
//				return 0;
//			}
//	}
//	while((c = fgetc(fp)) != '\n' && c != EOF)
//		fputc(c, stdout);
//	printf("\n");
	for(i = 1; i <= n; i++)
	{
		if((fgets(s, 20, fp)) == NULL)
		{
			printf("Line No Error.\n");
			return 0;
		}	
	}
	printf("%s", s);
	if(n != 1)
		printf("\n");
	fclose(fp);
	return 0;
}

//教训1：最后记得fclose！
//教训2：FILE全大写！
//教训3：(c = fgetc(fp)) != '\n' && (c = fgetc(fp)) != EOF不能这么写！否则指针一下就跳了两格！可以改成：(c = fgetc(fp)) != '\n' && c != EOF
//教训4：乐学fopen不要后缀名！
//教训5：之前写的用fgetc遍历的方法会出现栈溢出的问题！(stack smashing detected)如果涉及到不同行的问题推荐使用fgets；