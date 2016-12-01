#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define PI 3.14159
#define MAX 10;
struct varType {
	char name[MAX];
	double var;
};
extern struct varType var[MAX];
void push(double);
double pop(void);
void toLower(char []);
void set_Var(char [], struct varType []);
void call_Math(char s[])
{
	double op2;
	toLower(s);
	if (strcmp(s, "sin") == 0)
		push(sin(pop()));
	else if(strcmp(s, "cos") == 0)
		push(cos(pop()));
	else if (strcmp(s, "exp") == 0)
		push(exp(pop()));
	else if (strcmp(s, "pow") == 0) {
		op2 = pop();
		push(pow(pop(), op2));
	} else if (strcmp(s, "pi") == 0)
		push(PI);
	else if (strlen(s) == 1)
		set_Var(s, var);
	else
		printf("error: %s doesn't available\n", s);
}

void toLower(char s[])
{
	int i;
	
	for (i = 0; s[i] != '\0'; i++)
		s[i] = tolower(s[i]);
}

void set_Var(char s[], struct varType var[])
{

}
