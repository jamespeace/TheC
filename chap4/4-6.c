#include <stdio.h>
#include <stdlib.h> 	/*for atof() */
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100 		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define MAXVAL 100 		/* maximum depth of val stack */
#define BUFSIZE 100
#define INIT 1
#define UNINIT 0
#define COMMAND 1
#define VARIABLE 2

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */
char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free buf position */
double var[26];			/* variables for ex 4.6 */
int vinit[26];			/* which vars hold a value */
int vdx = -1;			/* index of next variable to be assigned */
double last;			/* Ex 4.6 - the most recent printed variable */
int getch(void);
void ungetch(int);
int getop(char []);
void push(double);
double pop(void);
void printtop(void);
void duplicate(void);
void swap(void);
void clear(void);
void parseCommand(char s[]);

int main(void)
{
	int type, i;
	double op2;
	char s[MAXOP];

	for (i = 0; i < 27; ++i) 	// initialzation.
		vinit[i] = UNINIT;		

	while (type = getop(s) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case COMMAND:		/* for ex 4.5 other math functions*/
				parseCommand(s);
				break;
			case VARIABLE:		/* ex 4.6 - handling variables */
				vdx = tolower(s[0]) - 'a';
				if (vinit[vdx] == INIT) {
					push(var[vdx]);
				}
				break;
			case '=':
				if (vdx == -1)
					printf("error: no variable to assign to\n");
				else if (sp == 0)
					printf("error: no value specified for variable\n");
				else {
					var[vdx] = pop();
					vinit[vdx] = INIT;
				}
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command %s\n", s);
				break;
			}
	}
}

/* push: push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	i = 0;

	if (isalpha(c)) {
		while (isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c);
		if (s[1] == '\0')
			return VARIABLE;
		else
			return COMMAND;
	}

	if (!isdigit(c) && c != '.' && c != '-')	//left number, '.' and '-'
		return c;

	if (c == '-') {
		if (!isdigit(c = getch()) || c != '.')
			ungetch(c);
			return '-';
		}
		else
			ungetch(c);
	
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c =getch()))
			;
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: buffer full\n");
}

void printtop(void)
{
	if (sp == 0)
		printf("error: no item in the stack\n");
	else 
		printf("top of stack is : %.8g\n", val[sp - 1]);
}

void duplicate(void)
{
	if (sp > 0) 
		val[sp++] = val[sp - 1];
	else
		printf("error: cann't duplicate the item\n");
}

void swap(void)
{
	if (sp > 1) {
		double d = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = d;
	} else 
		printf("error: cann't swap the item\n");
}

void clear(void)
{
	sp = 0;
}

void viewstack(void)
{
	int i;
	if (sp <= 0)
		printf("stack empty\n");
	else {
		printf("\t");
		for (i = 0; i < sp; ++i)
			printf("%.8g ", val[i]);
		printf("\n");
	}
}

void viewvars(void)
{
	int i;

	for (i = 0; i < 26; ++i)
		printf("%.8g ", var[i]);
	printf("\n");
}

void parseCommand(char s[])
{
	double t;

	if(strcmp(s, "view") == 0)
		printtop();
	else if (strcmp(s, "duplicate") == 0)
		duplicate();
	else if (strcmp(s, "swap") == 0)
		swap();
	else if (strcmp(s, "clear") == 0)
		clear();
	else if(strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if(strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if(strcmp(s, "pow") == 0) {
		t = pop();
		push(pow(pop(), t));
	} else if (strcmp(s, "stack") == 0)
		viewstack();
	else if(strcmp(s, "vars") == 0)
		viewvars();
	else
		printf("error: not a valid  command\n");
}
