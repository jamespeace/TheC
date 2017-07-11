#include <unistd.h>

void filecopy(int ifd, int ofd)
{
    int n;
    char buf;

    while ((n = read(ifd, &buf, 1)) > 0)
        write (ofd, &buf, n);
}
