#include <stdio.h>
#define MAXVAL 100 		/* maximum depth of val stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];

/* push:  push f onto value stack */
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else 
		printf("error: stack full, can't push %g\n", f);
}




/* pop:  pop and return top value from stack */
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

int isEmpty(void)
{
	return (sp == 0) ? 1 : 0;
}

void clearStack(void)
{
	sp = 0;
}

void printTop(void)
{
	printf("%.8g\n", val[sp - 1]);
}

void duplicate(void)
{
	if (sp < MAXVAL) {
		val[sp++] = val[sp - 1];
	} else {
		printf("error: stack full\n");
	}
}

void swap(void)
{
	double d;

	if (sp > 1) {
		d = val[sp - 1];
		val[sp - 1] = val[sp - 2];
		val[sp - 2] = d;
	} else {
		printf("error: only one variable\n");
	}
}
