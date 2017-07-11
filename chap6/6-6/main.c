#include "table.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int getword(char *, int);
void printhash(struct nlist **, int);
struct nlist *install(char *, char *);
struct nlist *lookup(char *);
char *strsdup(const char *);
unsigned hash(char *);
void freehash(struct nlist **, int);

static struct nlist *hashtab[HASHSIZE];

int main(void)
{
	char word[MAXWORD];
	char name[20], defn[20];

	while ((getword(word, MAXWORD)) != EOF) {
		if (strcmp(word, "#define") == 0) {
			getword(word, MAXWORD);
			strcpy(name, word);
			getword(word, MAXWORD);
			strcpy(defn, word);
			if (install(name, defn) == NULL) {
				perror("can't install");
				exit(1);
			}
		} else {
			perror("Syntax: #define \n");
			exit(1);
		}
	}

	printhash(hashtab, HASHSIZE);
	freehash(hashtab, HASHSIZE);
	return 0;
}


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
	} else 			/* already there */
		free((void *) np->defn);	/* free previous defn */
	if ((np->defn = strsdup(defn)) == NULL)
		return NULL;
	return np;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(np->name, s) == 0)
			return np;	/* found */
	return NULL;		/* not found */
}

