/*
 * treefree.c
 * Copyright (C) 2017 james <james@james-MacBookPro>
 *
 * Distributed under terms of the MIT license.
 */
#include <stdio.h>
#include <stdlib.h>
#include "tnode.h"

void linefree(struct lcount *);

void treefree(struct tnode *p)
{
	if (p == NULL)
		return;
	if (p->left != NULL)
		treefree(p->left);
	if (p->right != NULL)
		treefree(p->right);
	if (p->lptr != NULL)
		linefree(p->lptr);
	free(p);
}
