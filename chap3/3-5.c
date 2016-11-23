#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void itob(int, char*, int);
void reverse(char*);

int main(void)
{
	int i, b;
	char s[15];

	printf("Input a number:");
	scanf("%d", &i);
	printf("Input the base b character:");
	scanf("%d", &b);

	itob(i, s, b);

	printf("Number is\"%s\"\n", s);

	return 0;
}

void itob(int n, char s[], int b)
{
	int i, sign, c;
	if (b < 2 || b > 36) {
		printf("ERROR! b is wrong!\n");
		exit(EXIT_FAILURE);
	}
	sign = (n < 0) ? -1 : 1;
	i = 0;
	do {
		s[i++] = ((c = abs(n % b)) <10) ? (c + '0') : (c - 10 + 'a');
	} while (n /= b);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[])
{
	int i, j;
	char temp;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
