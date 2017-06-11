#include "calc.h"
#include <string.h>
#include <stdio.h>
#define BUFFSIZE 100

//char buff[BUFFSIZE]; /* Buffer for our version of ungetch */
int buff[BUFFSIZE]; /* Lazy modification that can handle EOF */
int buffp = 0; /* Next free position in buffer */

/* Single character of input */
int getch_1(void) {
    return (buffp > 0) ? buff[0] : getchar();
}

void ungetch_2(int c) {
    if (buffp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[0] = c;
}


/* getch: gets the next possible pushed back character */
int getch(void) {
    return (buffp > 0) ? buff[--buffp] : getchar();
}

/* ungetch: pushes a character back on input */
void ungetch(int c) {
    if (buffp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else
        buff[buffp++] = c;
}

void ungets(char s[]) {
    unsigned int i, str_len;
    for (i = 0, str_len = strlen(s); i < str_len; i++)
        ungetch(s[i]);

    return;
}

