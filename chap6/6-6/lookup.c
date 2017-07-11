#include <stdio.h>
#include <string.h>
#include "table.h"
#include <stdlib.h>

extern struct nlist *hashtab[HASHSIZE];

unsigned hash(char *);

/* lookup:  look for s in hashtab */
struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(np->name, s) == 0)
			return np;	/* found */
	return NULL;		/* not found */
}
