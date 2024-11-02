#include <stdio.h>
int special(int a, int b)
{
	if((0 == a) || (0 == b)) return 0;
	if(a < 1000) a = 1000;
	if(b > 9999) b = 9999;
	int counter = 0, array[5];
	for(int i = a; i <= b; i++)
	{
		int flag = 1, i_copy;
		i_copy = i;
		if(0 != i%2) flag = 0;
		else
		{
			for(int j = 4; j >= 1; j--)
			{
				array[j] = i_copy%10;
				i_copy = i_copy/10;
			}
			for(int j = 1; j <=3; j++)
			{
				for(int k = j+1; k <= 4; k++)
				{
					if((array[j]^array[k]) == 0)
					{
						flag = 0;
						goto p;
					}
				}
			}
		p:	if(1 == flag)
			{
				printf( "%d  ", i);
				counter++;
			}
		}
	}
	if(counter != 0) printf("\ncounter=%d\n", counter);
	else printf("Error\n");
	return 0;
}

int main()
{
	int a1, b1, a2, b2, a3, b3;
	scanf("%d%d%d%d%d%d", &a1, &b1, &a2, &b2, &a3, &b3);
//	scanf("%d%d", &a1, &b1);
	special(a1, b1);
	special(a2, b2);
	special(a3, b3);
	return 0;
}