#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CATNUM 100000

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

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF)
        putc(c, ofp);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *prog = argv[0];
    struct timespec start, end;
    double cpu_time1;
    int i;

    if (argc == 1)  /* no args; copy standard input */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf(stderr, "%s: can't open%s\n",
                        prog, *argv);
                exit(1);
            } else {
                clock_gettime(CLOCK_REALTIME, &start);
                for (i = 0; i < CATNUM; i++) {
                    filecopy(fp, stdout);
                }
                clock_gettime(CLOCK_REALTIME, &end);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writin stdout\n", prog);
        exit(2);
    }
    cpu_time1 = diff_in_second(start, end);

    FILE *output;
    output = fopen("cat.txt", "a");
    fprintf(output, "fcat() %d times\nnsec:%lf\n", CATNUM, cpu_time1);
    fclose(output);
    exit(0);
}

