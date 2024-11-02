#include <stdio.h>


int leap( int year)
{
	if(( year % 100 != 0 && year % 4 == 0) || ( year % 400 == 0)) return 2;
	else return 1;
}

int monthdays( int year, int month)
{
	switch( month)
	{
		case 1: return 3; break;
		case 2: if( 2 == leap( year)) return 1;
				else return 0;
				break;
		case 3: return 3; break;
		case 4: return 2; break;
		case 5: return 3; break;
		case 6: return 2; break;
		case 7: return 3; break;
		case 8: return 3; break;
		case 9: return 2; break;
		case 10: return 3; break;
		case 11: return 2; break;
		case 12: return 3; break;
	}
}

int co(int year, int month, int day)
{
	int week = 1, day_mod;
	for( int l = 1901; l <= year; l++) week = ( week + leap( l - 1)) % 7;
	for( int l = 2; l <= month; l++) week = ( week + monthdays( year, l - 1)) % 7;
	week = ((week + day - 1) % 7)==0?7:(week + day - 1) % 7;
	day_mod = day%10;
	if(week == day_mod)
		return week;
	else
		return 0;
}

int main()
{
	int year_b, month_b, day_b, year_e, month_e, day_e, week = 1, day, co_day[8] = {0}, sum = 0;
	while(scanf("%d", &year_b) != EOF)
	{
		scanf( "%d%d%d%d%d", &month_b, &day_b, &year_e, &month_e, &day_e);
		if(year_b == year_e)
		{
			if(month_b == month_e)
			{
				for(int i = day_b; i <= day_e; i++)
				{
					if(co(year_b, month_b, i))
						co_day[co(year_b, month_b, i)]++;
				}
			}
			else
			{
				for(int i = month_b+1; i <= month_e-1; i++)
				{
					for(int j = 1; j <= monthdays(year_b, i)+28; j++)
					{
						if(co(year_b, i, j))
							co_day[co(year_b, i, j)]++;
					}
				}
				for(int i = month_b; i <= month_b; i++)
				{
					for(int j = day_b; j <= monthdays(year_b, i)+28; j++)
					{
						if(co(year_b, i, j))
							co_day[co(year_b, i, j)]++;
					}
				}
				for(int i = month_e; i <= month_e; i++)
				{
					for(int j = 1; j <= day_e; j++)
					{
						if(co(year_b, i, j))
							co_day[co(year_b, i, j)]++;
					}
				}								
			}
		}
		else
		{
			for(int i = year_b+1; i <= year_e-1; i++)
			{
				for(int j = 1; j <= 12; j++)
				{
					for(int k = 1; k <= monthdays(i, j)+28; k++)
					{
						if(co(i,j,k))
							co_day[co(i,j,k)]++;
					}
				}
			}
			for(int i = year_b; i <= year_b; i++)
			{
				for(int i = month_b+1; i <= 12; i++)
				{
					for(int j = 1; j <= monthdays(year_b, i)+28; j++)
					{
						if(co(year_b, i, j))
							co_day[co(year_b, i, j)]++;
					}
				}
				for(int i = month_b; i <= month_b; i++)
				{
					for(int j = day_b; j <= monthdays(year_b, i)+28; j++)
					{
						if(co(year_b, i, j))
							co_day[co(year_b, i, j)]++;
					}
				}
			}
			for(int i = year_e; i <= year_e; i++)
			{
				for(int i = 1; i <= month_e-1; i++)
				{
					for(int j = 1; j <= monthdays(year_e, i)+28; j++)
					{
						if(co(year_e, i, j))
							co_day[co(year_e, i, j)]++;
					}
				}
				for(int i = month_e; i <= month_e; i++)
				{
					for(int j = 1; j <= day_e; j++)
					{
						if(co(year_e, i, j))
							co_day[co(year_e, i, j)]++;
					}
				}
			}
		}
		for(int i = 1; i <= 7; i++)
			sum += co_day[i];
		printf("%d ", sum);
		int i = 1;
		for(; i <= 6; i++)
		{
			printf("%d ", co_day[i]);
		}
		printf("%d\n", co_day[i]);
	}
	return 0;
}

//教训1：小心同年同月的情况！；
//教训2：自己编的函数：循环起始值要 +1！；
//教训3：每次使用的时候需要初始化 week！；
//教训4：初始年、月、日，结束年、月、日需要专门考虑；
//教训5：难绷，monthdays 函数返回的只是星期的差值，不是该月有多少天……

//		if(year_b != year_e)
//		{
//			for(int i = month_b; i<= 12; i++)
//			{
//				for(int j = 1; j <= monthdays(year_b, i); j++)
//				{
//					if(co(year_b,i,j))
//						co_day[year_b,i,j]++;
//				}
//			}
//			for(int i = 1; i<= month_e; i++)
//			{
//				for(int j = 1; j <= monthdays(year_e, i); j++)
//				{
//					if(co(i,j,k))
//						co_day[week]++;
//				}
//			}	
//		}
//		else
//		{
//			for(int i = month_b; i<= month_e; i++)
//			{
//				for(int j = 1; j <= monthdays(year_b, i); j++)
//				{
//					if(co(i,j,k))
//						co_day[week]++;
//				}
//			}
//		}