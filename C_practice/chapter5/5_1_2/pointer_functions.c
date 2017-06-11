#include <stdio.h>
#include <ctype.h>

#include "test.h"

#define SIZE 2

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void incorrect_swap(int *x, int *y) {
    int *temp;
    temp = x;
    x = y;
    y = temp;
}


void test_getint() {
    int n, i, array[SIZE];
    for (n = 0; n < SIZE; n++)
        array[n] = -1; /* Init with fucking default values  */
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    for (i = 0; i < SIZE; i++)
        printf("value %d: %d\r\n", i, array[i]);
}


void test_getfloat() {
    int n, i;
    double array[SIZE];

    for (n = 0; n < SIZE; n++)
        array[n] = 1.0;
    for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
        ;
    for (i = 0; i < SIZE; i++)
        printf("value %d: %f\r\n", i, array[i]);
}
/*
 * getint: reads the the next integer from intput in pn
 * shit just assumes any blank value will be fucking zero
 * the book is super ambigious here to solve CHECK 5_1 to fix
 * later
 */
int getint(int *pn) {
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    if (!isdigit(c))
        ungetch(c);

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}

int getfloat(double *pn) {
    int c, sign, factor;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }
    puts("there is a plus or minus sign");
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    printf("pn value after first half %f\n", *pn);
    if (c == '.')
        c = getch();

    for (factor = 1; isdigit(c); c = getch(), factor *= 10)
          *pn = 10 * *pn + (c - '0');

    *pn = (*pn / factor) * sign;

    if (c != EOF)
        ungetch(c);

    return c;
}
