#include <stdio.h>

/* We only want 19 characters plus NULL term */
#define MAX_ARR_SIZE 20


/* Function Definitions (Prototypes) */
void init_arr(char s[]);
void copy(char s[]);
void escape(char t[], char s[]);
int default_m(void);


int main(int argc, char ** argv) {
    char t[MAX_ARR_SIZE];
    char s[MAX_ARR_SIZE];

    /* Intialize both arrays */
    init_arr(t);
    init_arr(s);

    /* Copy input from std int */
    copy(s);
    printf("S input: %s\r\n", s);

    /* Covert those stupid characters */
    escape(t, s);

    printf("copied target text: %s\r\n", t);
    //int q =  default_m();
    return 0;
}


/*
 * Initializes a character array
 * Maybe create macro later
 */
void init_arr(char s[]) {
    unsigned int i;
    for (i = 0; i < MAX_ARR_SIZE; i++)
        s[i] = '\0';

    return;
}


/* Copies the input from stdin */
void copy(char s[]) {
    int c;
    unsigned int i;
    for (i = 0; (c = getchar()) != EOF && i < MAX_ARR_SIZE; i++)
        s[i] = c;

    /* NULL terminate */
    s[i] = '\0';
}

void escape(char t[], char s[]) {
    int c;
    unsigned int i;
    for (i = 0; (c = s[i]) != '\0' && i < MAX_ARR_SIZE; i++)
        switch (c) {
            case '\n':
                t[i] = '\\';
                i++;
                t[i] = 'n';
                break;
            case '\t':
                printf("Tab found");
                t[i] = '\\';
                i++;
                t[i] = 't';
                break;
            default:
                t[i] = c;
                break;
        }
    t[i] = '\0';
}


/* count digits, white space, others */
int default_m(void) {
    int c, i, nwhite, nother, ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        switch(c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ndigit[c - '0']++;
                break;

            case ' ':
            case '\n':
            case '\t':
                nwhite++;
                break;

            default:
                nother++;
                break;
        }
    } //END-WHILE

    printf("digits = ");
    for (i = 0; i < 10; i++)
        printf(" %d", ndigit[i]);

    printf(", white space = %d, other = %d\n", nwhite, nother);

    return 0;
}
