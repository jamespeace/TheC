#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* error: print an error message and die */
void errors(char *fmt, ...)
{
    va_list args;

    va_start(args, fmt);
    fprintf(stderr, "error: ");
    vfprintf(stderr, fmt, args);
    fprintf(stderr, "\n");
    va_end(args);
    exit(1);
}

int main(void)
{
    errors("hello world!%d, %d", 1, 2);
    return 0;
}
