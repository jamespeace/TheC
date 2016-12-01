#include<stdio.h>
#include<stdlib.h>
void reverse(char *);
int length(char *);

int main(void) {
    char s[10] = {"Hello"};
    reverse(s);
    printf("%s\n", s);

    return 0;
}

void reverse(char *s) {
    int i, j;
    char temp;
    i = 0;
    j = length(s) - 1;

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int length(char *s) {
    int i;
    i = 0;

    while (s[i++] != '\0');

    return --i;


}
