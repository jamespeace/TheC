/*
 * lalloc.c
 * Copyright (C) 2017 james <james@james-MacBookPro>
 *
 * Distributed under terms of the MIT license.
 */

#include "tnode.h"
#include <stdio.h>
#include <stdlib.h>

struct lcount *lalloc(void)
{
	return (struct lcount *) malloc (sizeof(struct lcount));
}
