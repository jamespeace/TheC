#include <stdio.h>
#include <string.h>

void itoa(int, char [], int);
void reverse(char s[], int, int);
int main(void)
{
	char s[10];
	itoa(30, s, 0);
	printf("%s\n", s);
	return 0;
}

void itoa(int n, char s[], int pos)
{
	if (n < 0) {
		n = -n;
		s[pos++] = '-';
	}

	if (n == 0) {
		s[pos] = '\0';
		reverse(s, 0, strlen(s)-1);
	}else {
		s[pos++] = n % 10 + '0';
		itoa(n / 10, s, pos);
	}
}

void reverse(char s[], int i, int j)
{
	char temp = 0;	
	if (i < j) {
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
}
