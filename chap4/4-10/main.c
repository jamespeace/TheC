#include <stdio.h>
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
		}
	}
	return 0;
}

int getop(char s[])
{

}
