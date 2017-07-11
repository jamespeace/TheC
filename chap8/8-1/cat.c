#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>

#define CATNUM 100000

void filecopy(int ifd, int ofd);

static double diff_in_second(struct timespec t1, struct timespec t2)
{
    struct timespec diff;

    if (t2.tv_nsec < t1.tv_nsec) {
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec + 1000000000;
        diff.tv_sec = t2.tv_sec - t1.tv_sec - 1;
    } else {
        diff.tv_nsec = t2.tv_nsec - t1.tv_nsec;
        diff.tv_sec = t2.tv_sec - t1.tv_sec;
    }
    return diff.tv_sec + (diff.tv_nsec / 1000000000.0);
}


int main(int argc, char *argv[])
{
    int fd, i;
    char *prog = argv[0];
    struct timespec start, end;
    double cpu_time1;

    if (argc == 1)
        filecopy(0, 1);
    else
        while (--argc > 0)
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) {
                fprintf(stderr, "%s: can't open %s\n",
                        prog, *argv);
                exit(1);
            } else {
                clock_gettime(CLOCK_REALTIME, &start);
                for (i = 0; i < CATNUM; i++) {
                    filecopy(fd, 1);
                }
                clock_gettime(CLOCK_REALTIME, &end);
                close(fd);
            }
    cpu_time1 = diff_in_second(start, end);

    FILE *output;
    output = fopen("cat.txt", "a");
#if defined(BUF)
    fprintf(output, "buf_cat()");
#else
    fprintf(output, "unbuf_cat()");
#endif
    fprintf(output, " %d times\nnsec:%lf\n", CATNUM, cpu_time1);
    fclose(output);

    return 0;
}
