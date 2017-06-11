#include <stdio.h>
#include <stdlib.h>
void count_new_lines(void);
void count_blanks(void);
void count_tabs(void);
void count_them_all(void);
void print_char(int car);
/**
 * Important things to note:
 *  getchar() will parse the input as a stream of bytes
 *  then go char by char and return the result
 *
 *  In order to parse chars you can use either the ascii equivalent
 *  or the decimal value
 */
int main() {
    //count_new_lines();
    //count_blanks();
    count_them_all();
}

void count_them_all() {
    int c, nl, bc, bsc, spc;
    nl = bc = bsc = spc = 0;
    while((c = getchar()) != EOF) {
        // Can compare ASCII decimal equivalen
        // as well as the actual ascii representation
        if (c == 8) { // back space
            spc = 0;
            printf("\\b");
            //print_char(atoi("\\b"));
        }
        else if (c == 9) { //horizontal tab
            spc = 0;
            printf("\\t");
            //print_char(atoi("\\t"));
        }
        else if (c == 10) { //new line
            spc = 0;
            printf("\\n");
            //print_char(atoi("\\n"));
        }
        else if (c == 32) { //space
            if(spc == 0) {
                spc++;
                print_char(c);
            }
        }
        else if (c == 92) { // backslash
            spc = 0;
            printf("\\\\");
            //print_char(atoi("\\\\"));
        }
        else {
            spc = 0;
            print_char(c);
        }

    }

}

void print_char(int car) {
    printf("%c", car);
}
void count_new_lines() {
    int c, nl;
    nl = 0;
    while((c = getchar()) != EOF)
        if(c == '\n') // n represents a character constant
            nl++;
    printf("%d\n", nl);

}
void count_blanks() {
    int c, bc = 0;
    while((c = getchar()) != EOF)
        if(c == ' ')
            bc++;
    printf("%d\n", bc);
}

void count_tabs() {
    int c, tc;
    tc = 0;
    for(; (c = getchar()) != EOF;)
        if(c == '\t')
            tc++;
    printf("%d", tc);
}
