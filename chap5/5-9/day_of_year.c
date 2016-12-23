#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}	
};

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	char *p;
	
	if (year < 0) {
		printf("error: unexpected year\n");
	}
	if (month < 0 || month > 13) {
		printf("error: unexpected month\n");
		return -1;
	}
	if (day < 0 || day > 31) {
		printf("error: unexpected day\n");
		return -1;
	}
	leap = ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0);
	p = &daytab[leap][1];
	for (i = 1; i < month; i++) {
		day += *p;
		p++;
	}
	return day;
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	char *p;

	if (year < 0) {
		printf("error: unexpected year\n");
		return ;
	}
	leap = ((year%4 == 0) && (year%100 != 0)) || (year%400 == 0);
	if (year< 0 || yearday > (365 + leap)) {
		printf("error: unexpected yearday\n");
	}
	p = &daytab[leap][1];
	for (i = 0; yearday > *p; i++) {
		yearday -= *p;
		p++;
	}
	*pmonth = i;
	*pday = yearday;
}

