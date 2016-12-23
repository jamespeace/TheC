#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main(void)
{
	int day, pmonth = 6, pday = 8;
	printf("1937/6/8 = %d days\n", day = day_of_year(1937, 6, 8));
	month_day(1937, day, &pmonth, &pday);
	printf("1937/%d/%d = %d days\n", pmonth, pday, day);
	return 0;
}
