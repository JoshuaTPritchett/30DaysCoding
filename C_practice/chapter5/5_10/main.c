#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "defs.h"

#define MAXOPS 100
#define MAXLINE 100
void test_stack(void);
void argv_print(int argc, char *argv[]);
void argv_calc(int argc, char *argv[]);


/* main: here is main */
int
main(int argc, char *argv[]) {
    //argv_print(argc, argv);
    argv_calc(argc, argv);
    return 0;
}


void argv_print(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s %s", *++argv, (argc > 1) ? " " : "");
    printf("\n");
}

void
argv_calc(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    double *val1;
    while (--argc > 0 && (c = (*++argv)[0])) {
            switch (c) {
                case '1': case '2': case '3':
                case '4': case '5': case '6':
                case '7': case '8': case '9':
                    push(atof(*argv));
                    break;
                case '+':
                    push(*(pop()) + *(pop()));
                    break;
                case '*':
                    puts("times");
                    push((*(pop())) * (*(pop())));
                    break;
                case '-':
                    val1 = pop();
                    push(*val1 - (*(pop())));
                    break;
                case ' ': case '\t':
                    ++argv;
                    break;
                default:
                    printf("error: unkown command: %c\n", c);
                    break;

            }
    }
    while ((val1 = pop()) != NULL)
        printf(" VALUE val1 :%f\n", *val1);
}
void
test_stack() {
    double *val1;
    push(atof("1"));
    push(atof("2"));
    push(atof("3"));
    while ((val1 = pop()) != NULL)
        printf("val %f\n", *val1);
}
