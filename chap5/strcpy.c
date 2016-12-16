/* strcpy: copy t to s; array subscript version */
void strcpy(char *s, char *t)
{
	int i;

	i = 0;
	while ((s[i] = t[i]) != '\0')
		i++;
}

/* strcpy:	copy t to s; pointer version 1 */
void strcpy(char *s, char *t)
{
	while ((*s++ = *t++) != '\0')
		;
}

/* strcpy: copy t to s; pointer version 3 */
void strcpy(char *s, char *t)
{
	while (*s++ = *t++)
		;
}
