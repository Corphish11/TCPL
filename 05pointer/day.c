/* day.c - convert between year day and month day */
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (month < 1 || month > 12)
		return -1;
	if (*(*(daytab + leap) + month) < day)
		return -1;
	for (i = 1; i < month; i++)
		day +=  *(*(daytab + leap) + i);
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (yearday > (leap ? 366 : 365) || yearday < 1)
		printf("error: wrong year day %d\n", yearday);
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

#define dprint(expr)	printf("%s is %d\n", #expr, expr)
main()
{
	int m, d;

	dprint(day_of_year(2009, 2, 29));
	dprint(day_of_year(2009, 2, 28));
	dprint(day_of_year(2008, 13, 1));

	month_day(2009, 58, &m, &d);
	printf("2009,58 is 2009-%d-%d\n", m, d); 
}
