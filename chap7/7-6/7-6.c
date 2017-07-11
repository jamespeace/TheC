#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 20

int main(int argc, char *argv[])
{
	FILE *fp1, *fp2;
	char line1[MAXLINE], line2[MAXLINE];
	float lineno = 0;
	char *detect1, *detect2;

	if (argc != 3) {
		fprintf(stderr, "Usage: %s file1 file2\n", *argv);
		exit(1);
	}
	if ((fp1 = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", *argv);
		exit(1);
	}
	if ((fp2 = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "Can't open %s\n", *argv);
		fclose(fp1);
		exit(1);
	}

	while (((detect1 = fgets(line1, MAXLINE, fp1)) != NULL) &
			((detect2 = fgets(line2, MAXLINE, fp2)) != NULL)) {
		lineno++;
		if (strcmp(line1, line2) != 0) {
			printf("lineno:%f\nline1:%s\nline2:%s\n",
					lineno, line1, line2);
			goto free;
		}
	}
	if ((detect1 == NULL) && (detect2 == NULL)) {
		printf("two files are identical\n");
		goto free;
	}
	// file 1 is empty
	if (!detect1) {
		printf("file1 is empty\n");
		goto free;
	}
	// file2 is empty
	if (!detect2) {
		printf("file2 is empty\n");
		goto free;
	}
free:
	fclose(fp2);
	fclose(fp1);
	return 0;
}
