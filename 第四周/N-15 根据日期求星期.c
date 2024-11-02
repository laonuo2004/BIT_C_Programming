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

int main()
{
	int year, month, day, week = 1;
	scanf( "%d%d%d", &year, &month, &day);
	for( int i = 1901; i <= year; i++) week = ( week + leap( i - 1)) % 7;
	for( int i = 2; i <= month; i++) week = ( week + monthdays( year, i - 1)) % 7;
	week = (week + day - 1) % 7;
	printf("%d\n", week);
	return 0;
}