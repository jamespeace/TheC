/*
 * test.c
 * Copyright (C) 2017 james <james@james-MacBookPro>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>

int getch(void);
int main(void)
{
	char c;

	while((c = getch()) != EOF) {
		if (c == '\n')
			c = '*';
		printf("%c", c);
	}
	return 0;
}
