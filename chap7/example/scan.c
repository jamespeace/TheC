#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	char *line;
	int day;
	char monthname[20];
	int year;
	int n;
	size_t zero;


	zero = 0;	
	line = NULL;
	while (getline(&line, &zero, stdin) > 0) {
		n = sscanf(line, "%d %s %d", &day, monthname, &year);
		printf("%d, %s\n", n, line);
		free(line);
		line = NULL;
		zero = 0;
	}
#if 0
	while (getline(line, sizeof(line)) > 0) {
		if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
			printf("valid: %s\n", line);	/* 25 Dec 1988 form */
		else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
			printf("valid: %s\n", line);	/* mm/dd/yy form */
		else
			printf("invalid: %s\n", line);	/* invalid form */
	}
#endif
	return 0;
}
