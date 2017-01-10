#include <ctype.h>
#include <stdio.h>

#define STRCON 1234
#define COMMENT 1111

/* getword:  get next word or character from input */
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c) && c != '_' && c != "\"" && c != '/') {
		*w = '\0';
		return c;
	}
	if (c == '"') {
		for ( ; --lim > 0; w++) {
			if ((*w = getch()) == '"') {
				*w = '\0';
				return STRCON; 
			}
		}
		fprintf(stderr, "error: string constant too long , without \"\n");
		exit(EXIT_FAILURE);
	}

	if (c == '/') {
		if((*w++ = c = getch()) == '/') {
			lim--;
			for ( ;--lim > 0; w++) {
				if ((*w = getch()) == '\n') {
					*w = '\0';
					return COMMENT 1111
				}
			}
		} else if (c == '*') {
			lim--;
			for ( ;--lim > 0; w++) {
				if ((*w++ = getch()) == '*') {
					if ((*w++ = getch()) == '/') {
						*w = '\0';
						return COMMENT;
					} else
						continue;
				}
			}
			fprintf(stderr, "error: comment line(/* */) too long , without */\n");
			exit(1);
		} else {
			fprintf(stderr, "Usage: // , /* */ \n");
			exit(1);
		}
	}
	for ( ; --lim > 0; w++)
		if (!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
