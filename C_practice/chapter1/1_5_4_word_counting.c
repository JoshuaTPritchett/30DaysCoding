#include <stdio.h>

#define IN 1 /* inside a word */
#define OUT 0 /* outside a word */
void word_counting();


int main(int argc, char **argv) {
    word_counting();
    return 0;
}


void word_counting() {
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;
    while((c = getchar()) != EOF) {
        nc++;
        //New line is 10
        if(c == 10)
            nl++;
        //Take into account for non-standard characters
        //&& has a higher operator precedence than ||
        if(c == ' ' || c == 32 || c == '\t' || c == 9 || c == '\n' || c == 10) {
            state = OUT;
        }
        //Count the number of words
        else if(state == OUT) {
            nw++;
            state = IN;
        }
    }
    printf("Number of characters %d\n", nc);
    printf("Number of non-c %d\n", nl);
}

