/* fgets: get at most n chars from iop */
char *fgetss(char *s, int n, FILE *iop)
{
	register int c;
	register char *cs;

	cs = s;
	while (--n > 0 && (c = getc(iop)) != EOF)
		if ((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

/* fputs: put string s on file iop */
int fputss(char *s, FILE *iop)
{
	int c;

	while (c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}
