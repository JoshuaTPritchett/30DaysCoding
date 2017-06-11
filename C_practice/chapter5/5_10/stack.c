#include "defs.h"
#include <stdio.h>

static double stk[MAXVALS];
static double *stkp = &stk[0];

void push(double c) {
    if (stk + MAXVALS - stkp < 0)
        printf("error: stack is too full\n");
    else {
        printf("stk %p\n", stk);
        printf("stkp %p\n", stkp);
        printf("stk + MAXVALS %p\n", stk + MAXVALS);
        printf("stk + MAXVALS - stkp %lu\n", stk + MAXVALS - stkp);

        *stkp = c;
        stkp++;
    }
}

double *pop() {
    if (stkp > &stk[0]) {
        stkp--;
        return stkp;
    }
    else {
        printf("error stack is empty\n");
        return NULL;
    }
}
