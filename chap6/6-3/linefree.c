/*
 * linefree.c
 * Copyright (C) 2017 james <james@james-MacBookPro>
 *
 * Distributed under terms of the MIT license.
 */

#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"

void linefree(struct lcount *p)
{
	if (p->next != NULL)
		linefree(p->next);
	free(p);
}
