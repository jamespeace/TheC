struct nlist *lookup(char *);

/* undef: remove a name and definition */
void undef(char *s)
{
	struct nlist *np1, *np2;

	if (lookup(s) == NULL)
		return ;
		
	for (np1 = hashtab[hash(s)], np2 = NULL; strcmp(np1->name, s) != 0 && np1->next != NULL; np2=np1, np1=np1->next)
		;
	if (np2 == NULL) {
		hashtab[hash(s)] = np1->next;
		free(np1);
	} else {
		np2->next = np1->next;
		free(np1);
	}
}
