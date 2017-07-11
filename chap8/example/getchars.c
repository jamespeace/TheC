#include <stdio.h>
#include <unistd.h>

/* getchar: unbuffered single character input */
int getchars(void)
{
    char c;

    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

/* getchar: simple buffered version */
int getcharss(void)
{
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n = 0) {
        n = read(0, buf, BUFSIZ);
        bufp = buf;
    }
    return (--n > 0) ? (unsigned char) *bufp++ : EOF;
}

int main(void)
{
    char c;

    while ((c = getchars()) != EOF) {
        printf("%c", c);
    }

    return 0;
}
