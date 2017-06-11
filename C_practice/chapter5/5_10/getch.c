#include "defs.h"
#include <ctype.h>

static char charbuff[MAXCHARS];
static char *cbp = &charbuff[0];

int getop (char *s) {
    int i, c;
    char *p = &s[0];
    while (isspace(*p = c = getch()) || c == '\t')
        ;

    *(p++)  = '\0';
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while(isdigits(*(p++) = c = getch()))
            ;
    if (c == '.')
        while (isdigit(*(p++) = c = getch()))

    *(p++) = '\0'
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


int getch() {
    return (charbuff + MAXCHARS - cbp >= charbuff) ? *(cbp--) : getchar();
}

void ungetch(int c) {
    if (charbuff + MAXCHAR - cbp >= MAXOPS + charbuff)
        printf("error: too many characters\n");
    else {
        *(cbp) = c;
        cbp++;
    }
}
