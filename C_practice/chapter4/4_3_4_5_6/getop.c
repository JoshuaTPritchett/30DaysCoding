
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int my_getline(char s[], int size) {
    int c;
    unsigned int i, read_len;
    i = 0;
    read_len = size - 1; /* Have to take into account new line character */

    while (i < read_len && ((c = getchar()) != EOF) && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    /* Case EOF is read */
    if (i == 0)
        i = -1;

    return i;
}


int getop_2(char s[], int size) {
    int i, c, str_len;

    str_len = my_getline(s, size);

    i = 0;
    while ((c = s[i++]) == ' ' || c == '\t')
        ;

    if (c == '-')
        c = s[i++];

    if(!isdigit(c) && c != '.')
        return c;

    return 1;
}
/* gettop: get the next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    /* Skip spaces or tabs */
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    i = 0;
    if (c == '-')
        s[++i] = c = getch();

    /* Determine if character is a number */
    if (!isdigit(c) && c != '.')
        return c;

    /* Collect integer */
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;

    /* Determine if fraction */
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    /* NULL terminate to complete number */
    s[i] = '\0';

    printf("S string %s\n", s);
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}


