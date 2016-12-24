/* I am not sure how to simply descript the things. 20161224 23:09*/
#include <stdio.h>

int main(int argc, char *argv[])
{
	int n = 4, i = 0, c, j;
	int argcount = --argc;
	char **argvector = ++argv;
		
	if (argcount > 0) {
		n = (*argvector)[0] - '0';
	} else {
		n = 4;
	}
	while ((c = getchar()) != EOF) {
		i++;
		if (i > n) {
			n = (--argcount > 0) ? (*++argvector)[0] - '0' : 4;
			i = 1;
		}

		if (c == '\t') {
			for (j = 0; j < (n - ((i - 1) % n)); j++)
				printf("*");
			i = 0;
			n = (--argcount > 0) ? (*++argvector)[0] - '0' : 4;
		} else {
			if (c == '\n') {
				i = 0;
				argcount = argc;
				argvector = argv;
				n = argcount > 0 ? (*argvector)[0] - '0' : 4;
			}
			printf("%c", c);
		}
	}
	return 0;
}
