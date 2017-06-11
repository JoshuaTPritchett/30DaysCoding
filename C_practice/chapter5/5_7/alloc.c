#include "definitions.h"
#include <stdio.h>
#define SIZE 10000 /* 10,000  total characters can be allocated */

static char buffer[SIZE];
static char *buffp = &buffer[0];

char *alloc(int n) {
    if (buffer + SIZE - buffp >= n) {
        /* we have space */
        buffp += n; /* add on the addtional required space */
        printf("buff value changed %p\n", buffp);
        printf("previous buff value: %p\n", buffp - n);
        return buffp - n; /*Old buffer position for n*/
    } else
        return 0;
}

void afree(char *p) {
    if (p >= buffer && p < buffer + SIZE)
        buffp = p; /* Reset the buffer to the old position */
}
