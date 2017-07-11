#include <stdarg.h>
#include <stdio.h>

void minprintf(char *fmt, ...)
{
	va_list ap;
	int ival;
	char *cval;
	double fval;

	va_start(ap, fmt);
	for (; *fmt; fmt++) {
		if (*fmt == '%') {
			switch(*++fmt) {
				case 'd':
					ival = va_arg(ap, int);
					putchar(ival + '0');
					break;
				case 's':
					cval = va_arg(ap, char *);
					while (*cval) {
						putchar(*cval);
						cval++;
					}
					break;
				case 'f':
					fval = va_arg(ap, double);
					printf("%lf", fval);
					break;
			}
		} else {
			putchar(*fmt);
		}
	}
}

int main(void)
{
	int a = 1;
	char *s = "hello world!";
	double pi = 3.14;

	minprintf("%d, %f, %s\n", a, pi, s);
	return 0;
}



