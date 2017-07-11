#include <unistd.h>
#include <stdio.h>

void filecopy(int ifd, int ofd)
{
    int n;
    char buf[BUFSIZ];

    while ((n = read(ifd, buf, 1)) > 0)
        write (ofd, buf, n);
}

