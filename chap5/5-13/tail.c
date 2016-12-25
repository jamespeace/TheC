/*
 * finished in Neihu 01:43 am . I'm good ! ^^
 * I will challenge pointers functions tomorrow !
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int getlines(char **line, int lim);

int main(int argc, char *argv[])
{
	int n = 3, p, i = -1, a = -1, j = 0;
	char c, **line, *ptr, s[10];
	if ( --argc == 1 && (*++argv)[0] == '-') {
		while (isdigit(c = *++argv[0]))
				s[j++] = c;
		if (*argv[0] == '\0') {
			s[j] = '\0';
			n = atoi(s);
		} else {
			printf("Usage: tail -n\n");
			exit(EXIT_FAILURE);
		}
	} else if (argc == 0) {
		n = 3;
	} else {
		printf("Usage: tail -n\n");
		exit(EXIT_FAILURE);
	}

	line = (char **)malloc(n * sizeof(char *));	
	while (getlines(&ptr, 100) > 0) {
		i = (i + 1) % n;
		line[i] = ptr;
		if (i == a)
			a = (a + 1) % n;
		if (a == -1) {
			printf("%s", *line);
			a = 0;
		} else {
			p = a - 1;
			do {
				p = (p + 1) % n;
				printf("%s", line[p]);
			} while (p != i);
		}
	}
	
	for(j = 0; j < n ;j++)
		free(line[i]);
	free(line);
	return 0;
}

int getlines(char **line, int lim)
{
	char c, s[lim];
	int i = 0;
	while (--lim > 0 && (c = getchar()) != '\n' && c != EOF) 
		s[i++] = c;		
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	*line = (char *)malloc((i + 1) * sizeof(char));
	for (i = 0; s[i] != '\0'; i++)
		(*line)[i] = s[i];
	(*line)[i] = '\0';
	return i;
}
