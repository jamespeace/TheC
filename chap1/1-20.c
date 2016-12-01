#include<stdio.h>
#include<stdlib.h>
#define num 8
int main(void) {
    int b, count;
    char c;
    b = count = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            putchar(c);
            b = 0;
        } else if (c == '\t') {
            count = num - b % 8;
            for (int i = 0; i < count;i++)
                putchar('#');
            b += count;
            count = 0;
        } else {
            putchar(c);
            b++;
        }
    }
    return(0);
}
