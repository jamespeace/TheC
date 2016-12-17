#include <stdio.h>
#include <ctype.h>

int atoi(char *s);
float atof(char *s);

int main(void)
{
	char s[] = "  -123";
	char t[] = "  -23.45";

	printf("%d\n", atoi(s));
	printf("%.3f\n", atof(t));
	return 0;
}

int atoi(char *s)
{
	int sum = 0, sign;
	
	while (isspace(s++))		/* skip space */

	if (*s == '+' || *s == '-')			// positive or negative
		sign = (*s++ == '-') ? -1 : 1;	// number

	while (*s != '\n' && isdigit(*s)) {
		sum = sum * 10 + (*s - '0');	/* don't code sum *= 10 + (*s - '0') */
		s++;
	}
	return sign * sum;
}

float atof(char *s)
{
	float sum = 0;
	int power = 1, sign;

	for ( ; isspace(*s); s++)
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s != '\n' && isdigit(*s)) {
		sum = sum * 10 + (*s - '0');
		s++;
	}

	if (*s++ == '.')
		while (*s != '\n' && isdigit(*s)) {
			sum = sum * 10 + (*s - '0');
			s++;
			power *= 10;
		}
	return sign * sum / power;	
}
