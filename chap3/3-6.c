#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void itoa(int, char*, int);
void reverse(char*);

int main(void)
{
	int i, width;
	char s[15];

	printf("Input a number:");
	scanf("%d", &i);
	printf("Input the width:");
	scanf("%d", &width);

	itoa(i, s, width);

	printf("Number is\"%s\"\n", s);

	return 0;
}

void itoa(int n, char s[], int width)
{
	int i, sign;

	sign = (n < 0) ? -1 : 1;
	i = 0;
	do {
		s[i++] = abs(n % 10) + '0';
	} while (n /= 10);
	if (sign < 0)
		s[i++] = '-';
	while (i < width)
		s[i++] = ' ';
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
