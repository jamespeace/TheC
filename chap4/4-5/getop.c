#include <stdio.h>
#include <ctype.h>
#define NUMBER '0'
#define MATH '1'
int getch(void);
void ungetch(int);

/* getop: get the next operator or numeric operand */
int getop(char s[])
{
	int i, c, g;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	i = 0;
	if (isalpha(c)) {			//alpha collection.
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		return MATH;
	}
	if (!isdigit(c) && c != '.' && c != '-') //return operand
		return c;
	if(c == '-') {
		if (!isdigit(g = getch()) && g != '.') {
			ungetch(g);			//push g back to buffer.Or can't print the result.
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
		ungetch(c);
	return NUMBER;
}
