#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
static char buf;
int getch(void);
void ungetch(int);

/* getop: get the next operator or numeric operand */
int getop(char s[])
{
	int i, c, g;

	if (buf == EOF || buf == ' ' || buf == 't') {
		while ((s[0] = c = getch()) == ' ' || c == '\t')
			;
		s[1] = '\0';
	}
	else 
		c = buf;
	if (!isdigit(c) && c != '.' && c != '-')
		return c;
	i = 0;
	if(c == '-') {
		if (!isdigit(g = getch()) && g != '.') {
			buf = g;
			return c;
		}
		s[++i] = c = g;	
	}
	if (isdigit(c))		/*collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		buf = c;
	return NUMBER;
}
