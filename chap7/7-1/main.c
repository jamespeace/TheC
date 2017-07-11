#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	int c, i;

	if (argc != 2) {
		perror("Usage: conver name\n");
		exit(1);
	}
	for (i = 0; (c = argv[1][i]) != '\0'; i++) {
		if (isupper(c))
			putchar(tolower(c));
		else if (islower(c))
			putchar(toupper(c));
		else
			putchar(c);
	}

	return 0;
}
