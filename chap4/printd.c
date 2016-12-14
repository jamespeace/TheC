#include <stdio.h>

void printd(int);

int main(void)
{
	int number;

	while (1) {	
		printf("Input a number:");
		scanf("%d", &number);
		printd(number);
		putchar('\n');
	}
	return 0;	
}

void printd(int number)
{
	int n;
	if (number < 0) {
		putchar('-');
		n = -n;
	}
	if (number / 10)
		printd(number / 10);
	putchar(number % 10 + '0');
}
