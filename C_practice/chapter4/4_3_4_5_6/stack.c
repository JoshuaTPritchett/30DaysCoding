#include <stdio.h>
#include "calc.h"

#define MAXVAL 100


/* Stack position */
int sp = 0;

/* Value stack*/
double val[MAXVAL];

/* push: pushes f onto the value stack */
void push(double f) {
    printf("f %f\n", f);
    /* Take the position location then increment for next value */
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
    printf("val sp[] %f\n", val[sp - 1]);
    return;
}

/* pop: pop and return top value from stack */
double pop(void) {
    /* Value may not have been placed yet, so take the position and move it down first */
    if (sp > 0) {
        return val[--sp];
    }
    else {
        printf("error: stack empty \n");
        return 0.0;
    }
}

void peek() {
    if (sp > 0)
        printf("Top element of the stack %f\n", val[sp]);
    else
        printf("error: the stack is empty nothing to print\n");
}

void clear_stack() {
    if (sp == 0) return;
    while (sp > 0)
        printf("element clear: \t%.8g\n", pop());
}

int get_stack_size() {
    return sp;
}

void swap_two() {
    double val1, val2;

    /* Check to make sure that there are elements on the stack */
    if (sp < 2) {
        printf("error: there aren;t two elements to swap on the stack\n");
        return;
    }

    /* Get the first element */
    val1 = pop();

    /* Get the second element */
    val2 = pop();

    push(val1);
    push(val2);

    return;
}

int print_elements() {
    unsigned int i;
    if (sp == 0)
        return -1;

    for (i = 0; i < sp; i++)
        printf("element at: %d, %f\n", i, val[i]);

    return 1;
}


