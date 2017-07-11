#include <stdio.h>
#include <stdarg.h>

/* minprintf: minimal printf with variable argument list */
void minprintf(char *fmt, ...)
{
	va_list ap;		/* pointer to each unnamed arg in turn */
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);	/* make ap point to 1st unnamed arg */
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int);
				putchar(ival + '0');
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++)
					putchar (*sval);
				break;
			default:
				putchar(*p);
				break;
		}
		va_end(ap);		/* clean up when done */
	}
}
