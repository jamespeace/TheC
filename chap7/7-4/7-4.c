#include <stdio.h>
#include <stdarg.h>

size_t minscanf(char *fmt, ...)
{
	va_list ap;	/* pointer to each unnamed arg in turn */
	char *p, *sval;
	int *ival;
	float *dval;

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%')
			continue;
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, float *);
				scanf("%f", dval);
				break;
			case 's':
				sval = va_arg(ap, char *);
				scanf("%s", sval);
				break;
		}
	}
}
int main(int argc, char *argv[])
{
	int i;
	float f;
	char s[20];

	printf("Float:");
	minscanf("%f", &f);
	printf("%f\nString:", f);
	minscanf("%s", s);
	printf("%s\nInetger:", s);
	minscanf("%d", &i);
	printf("%d\n", i);
	return 0;
}
