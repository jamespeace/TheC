#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <ctype.h>
#include <math.h>
#define MAXOP 100		/* max size of operand or operator */
#define NUMBER '0'		/* signal that a number was found */
#define MATH '1'
struct varType {
	char name[MAXLEN];
	double var;
};
int getop(char []);
void push(double);
double pop(void);
int isEmpty(void);
void clearStack(void);
void printTop(void);
void duplicate(void);
void swap(void);
void call_Math(char []);
/* reverse Polish calculator */
int main(void)
{
	int type;
	double op2;
	char s[MAXOP];
	struct varType var[MAX];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case MATH:
				call_Math(s);
				break;
			case NUMBER:
				push(atof(s));
				break;
			case '%':
				if (op2 = pop())
					push(fmod(pop(), op2));
				else
					printf("error: zero divisor\n");
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
				if (op2 != 0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			case '!': 
				printTop();
				break;
			case '@':
				duplicate();
				break;
			case '#':
				swap();
				break;
			case '$':
				clearStack();
				break;
			default:
				printf("error: unknown command %s\n", s);
		}
	}
	return 0;
}


