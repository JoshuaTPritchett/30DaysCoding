#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_ARR_SIZE 100

int atoi_n(char s[]);
void reverse(char s[]);
void expand(char t[], char s[]);
void input_fill(char s[]);


int main(int argc, char **argv) {
    char s[] = {'1', '2', '3',  '4'};
    int a = atoi_n(s);

    char c = itoa(1);
    print
    printf("A value %d\r\n", a);

    char arr[MAX_ARR_SIZE + 1]; /* Allocate 101 characters */
    unsigned int i, j;
    for (i = 'a', j = 0; j < 26; i++, j++)
        arr[j] = i;
    arr[j] = '\0';

    reverse(arr);
    printf("The string reversed %s\r\n", arr);

    char t[MAX_ARR_SIZE + 1];
    input_fill(s);
    printf("S value :%s\r\n", s);

    expand(t, s);
    printf("T value :%s\r\n", t);
    return 0;
}

void input_fill(char s[]) {
    unsigned int c, i;
    i = 0;
    while ((c = getchar()) != EOF)
        s[i++] = c;

    /* Append null terminator */
    s[i] = '\0';
}

void expand(char t[], char s[]) {
    unsigned int i, n, c, q;
    i = n = c = q = 0;

    for (i = 0; isspace(s[i]); i++); /* iterate over spaces */

    if (s[i] == '-')
        i++; /* remove any additional - */

    /* Iterate through rest of array */
    while (s[i] != '\0' && q < MAX_ARR_SIZE) {
        if (s[i] == '-')
            for (c = s[i - 1], n =0; c + n  <= s[i + 1]; n++, q++)
               t[q] = c + n;
        i++;
    }

    /* Append the NULL terminator to the target string */
    t[q] = '\0';

    return;
}

/*
 * Converts a given ascii char array into integer
 * takes into consideration sign value.
 */
int atoi_n(char s[]) {
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) /* skip white spaces */
    ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        i++;

    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}


void reverse(char s[]) {
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[j], s[j] = s[i], s[i] = c;
}
