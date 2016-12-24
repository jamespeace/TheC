#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define VALSIZE 100

double val[VALSIZE];
int sp = 0;

void push(double c)
{
	if (sp < VALSIZE)
		val[sp++] = c;
	else
		printf("error: val full\n");
}

double pop(void)
{
	return (sp > 0) ? val[--sp] : 0.0;
}

int main(int argc, char *argv[])
{
	int op, op2;

	if (argc == 1) {
		printf("Usage: expr argument argument ...\n");
		exit(EXIT_FAILURE);
	}
	while (--argc > 0) {
		op = (*++argv)[0];
		if (isdigit(op))
			push(atof(argv[0]));
		else {
			switch(op) {
				case '+':
					push(pop() + pop());
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					if ((op2 = pop()))
						printf("error: zero divided\n");
					else
						push(pop() / op2);
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				default:
					printf("error:unknown character %s\n", *argv);
					break;
			}
		}	
	}
	printf("answer:%.2f\n", pop());
	return 0;
}
