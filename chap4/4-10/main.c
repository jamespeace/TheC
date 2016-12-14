#include <stdio.h>
<<<<<<< HEAD
#define MAXSIZE 100

int getop(char []);

int main(void)
{
	char s[MAXSIZE], c;

	while ((type = getop()) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				if (op2 = pop())
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
=======
#include <stdlib.h>
#include "calc.h"
#define MAXOP 100

int main(void)
{
	int type;
	double op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() -op2);
			break;
		case '/':
			if((op2 = pop()) == 0.0)
				printf("error: zero divisor\n");
			else
				push(pop() / op2);
			break;
		case '\n':
			printf("\t%.8g\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
>>>>>>> 21c423113edc7ad9898d928ecba2a80e71ef19dd
		}
	}
	return 0;
}

<<<<<<< HEAD
int getop(char s[])
{

}
=======
>>>>>>> 21c423113edc7ad9898d928ecba2a80e71ef19dd
