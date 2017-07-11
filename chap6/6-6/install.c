#include "table.h"
#include <stdio.h>
#include <stdlib.h>

struct nlist *lookup(char *);
char *strsdup(char *);
unsigned hash(char *);

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
		np->next = hashtab[HASHSIZE];
		hashtab[HASHSIZE] = np;
	} else 			/* already there */
		free((void *) np->defn);	/* free previous defn */
	if ((np->name = strsdup(defn)) == NULL)
		return NULL;
	return np;
}
