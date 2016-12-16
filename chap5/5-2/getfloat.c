#include <stdio.h>
#include <ctype.h>
int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
	int c, sign;
	float power;
	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		if(!isdigit(c = getch()) && c != '.') {
			ungetch(c);
			ungetch((sign == 1) ? '+' : '-');
		}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	if (c == '.')
		c = getch();
	for (power = 1.0; isdigit(c); c = getch(), power *= 10)
		*pn = 10.0 * *pn  + (c - '0');
	*pn = sign * *pn / power;
	if (c != EOF)
		ungetch(c);
	return c;
}

int main(void)
{
	float f = 0;

	printf("Input a float number:");
	getfloat(&f);
	printf("%.1f\n", f);
	return 0;
}
