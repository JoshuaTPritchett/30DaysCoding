#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

#define MAXOP 100 /* Max size of operator or operand */

void rpn(void);



int main(int argc, char **argv) {
    //test();
    rpn(); /* Call reverse polish notation */
    return 0;
}



void rpn(void) {
    int type; /* int used to identify the cases */
    double op2;
    char s[MAXOP]; /* Will be the buffer to parse operators */

    /* New way to parse operators that extends getc() */
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            /*
             * For division and subtraction operands must be in the desired order
             * since multiplication and addition are communitive then the order
             * in which the operands are popped doesnt matter
             *
             * Example:
             *  This would cause the number that was supposed to be subtracted to be the
             *  number that is subtracting
             *  push(pop() - pop());
             */
            case '-':
                puts("MINUS");
                /* In this case we want to pop the first value then subtract it from the original */
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");
                break;
            case '%':
                op2 = pop();
                push((int)pop() % (int)op2);
                break;
            case '\n':
                break;
            case 'p':
                peek();
                break;
            case 's':
                swap_two();
                break;
            case 'c':
                if (get_stack_size() > 0) {
                    puts("clearing stack");
                    clear_stack();
                }
                else
                    puts("error: stack is empty");
                break;
            case 'r':
                if(!print_elements())
                    printf("There were no elements to print\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }

    }

    return;
}




