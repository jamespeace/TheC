#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILE 10
#define MAXLINE 20

struct file {
	FILE *fp;
	char *name;
};

int main(int argc, char *argv[])
{
	struct file file[MAXFILE];
	char line[MAXLINE];
	char *prog = *argv;
	char *pattern;
	int except = 0, number = 0, count = 0;
	float lineno = 0;
	int i = 0;

	while (--argc > 0 && (*++argv)[0] == '-') {
		switch (*++argv[0]) {
			case 'x':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				fprintf(stderr, "error: iilgal option\n");
				exit(1);
		}
	}
	// don't have pattern
	if (argc == 0) {
		fprintf(stderr, "Usage: %s [-x] [-n] pattern [file1] [file2] ...\n", prog);
		exit(1);
	}
	pattern = *argv;

	// open files, max = 10
	while (count < 10 && (*++argv != NULL)) {
		if ((file[count].fp = fopen(*argv, "r")) != NULL) {
			file[count].name = *argv;
			count++;
		} else {
			fprintf(stderr, "can't open file: %s\n", *argv);
			continue;
		}
	}

	if (count == 0) {
		lineno = 0;
		while (fgets(line, MAXLINE, stdin) != NULL) {
			lineno++;
			if ((strstr(line, pattern) != NULL) != except) {
				if (number)
					printf("%f:", lineno);
				printf("%s", line);
			}
		}
	} else
	for (i = 0; i < count; i++) {
		lineno = 0;
		while (fgets(line, MAXLINE, file[i].fp) != NULL) {
			lineno++;
			if ((strstr(line, pattern) != NULL) != except) {
				printf("%s:\n", file[i].name);
				if (number)
					printf("%f:", lineno);
				printf("%s", line);
			}
		}
	}

	// close file descriptor
	for (i = 0; i < count; i++)
		fclose(file[i].fp);
	return 0;
}
