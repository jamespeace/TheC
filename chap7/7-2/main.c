#include <stdio.h>

#define HEXA 0x010
#define OCT  0x001
#define ERROR 0x100
#define LENGTH 10

int detect(int , char **);

int detect(int argc, char *argv[], int *format)
{
	char c;

	if (argc == 1) {
		perror("Usage: print -xo\n");
		exit(1);
	}
	while (--argc > 0) {
		if ((++argv)[0] == "-") {
			while ((c = *++argv[0]) != '\0') {
				switch(c) {
					case 'o': case 'O':
						*format += OCT;
						break;
					case 'x': case 'X':
						*format += HEX;
					default:
						perror("Usage: ./print -[xo]\n");
				}
			}
		} else {
			perror("Usage: ./print -xo\n");
			exit(1);
		}
	}	

	if (*format == 0x011) {
		perror("Do't allow to use -xo simultanously\n");
		exit(1);
	}

	return 0;
}

int canprint(int c)
{
	char *s = "abcdefghijklmnopqrstuvwxyz";


}
int main(int argc, char *argv[])
{	

}

