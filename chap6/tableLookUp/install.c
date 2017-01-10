#include "table.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned hash(char *);
struct nlist *lookup(char *);
char *strsdup(char *);

/* install:  put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL) {	/* not found */
		np = (struct nlist *) malloc(sizeof(*np));
		if (np == NULL || (np->name = strsdup(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next = hashtab[hashval];
		hashtab[hashval] = np;
	} else		/* already there */
		free((void *) np->defn);	/* free previous defn */
	if ((np->defn = strsdup(defn)) == NULL)
		return NULL;
	return np;
}
