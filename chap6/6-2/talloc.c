#include <stdlib.h>
#include <stdio.h>
#include "tnode.h"

/* talloc:  make a tnode */
struct tnode *talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
}
