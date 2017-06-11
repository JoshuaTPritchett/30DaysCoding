#include <stdio.h>


#define IN 1
#define OUT 0
void length_words(void);
//There are 12 types of input in c
//Use array to count occurences of characters
main()
{
    length_words();
}

void length_words(void) {
    int lwords[25];//Up to 25 characters
    int i, c, nc, state;

    i = nc = c = 0;
    state = IN;

    for(i = 0; i < 25; i++)
        lwords[i] = 0;

    while((c = getchar()) != EOF) {
        //The case in which it's not a word
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else {
            nc++;
            printf("c: %c  nc: %d\n", c, nc);
        }
        if(state == OUT) {
            if(nc < 25)
                ++lwords[nc];
            else
                printf("Word length too long");
            nc = 0;
            state = IN;
        }
    }
    //Find the max length of a value
    int max_length = 0;
    for(i = 0; i < 25; i++)
        if(lwords[i] != 0)
            max_length = i;


    printf("Length   |");
    //Print out the total values that can appear
    for(i = 0; i < max_length; i++) {
        printf("      %d", i + 1);
    }
    puts("\n");
    int q = 0;
    //Print out the values for up to length of 25
    for(i = 1; i < 25; i++) {
        printf("%d  |",i);
        //Print out number of occurences of each length
        for(q = 0; q < lwords[i]; q++) {
            printf("  x");
        }
        printf("\n");
    }
}


void frequency_char() {
    int c, i, nwhite, nother, max_value;
    int ndigit[10];
    nwhite = nother = max_value = 0;
    //Init the array
    for(i = 0; i < 10; i++)
        ndigit[i] = 0;
    int nc;
    int state = IN;
    int nwords = 0;
    while((c = getchar()) != EOF && nwords < 10) {
        nc++; //get the number of characters
        if (c >= '0' && c <= '9')
            ++ndigit[c - '0']; //whoa
            //Any char digit - '0' will produce the integer equivalent
        else if(c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            ++nwhite;
        }
        if (state == OUT) {
            if (nc < 25) ++ndigit[nc];
            nc = 0;
        }
        else {
            ++nother;
        }
    }

    for(i = 0; i < 10; i++)
        if (ndigit[i] > max_value)
            max_value = ndigit[i];
    int q;
    for (i = 0; i < max_value; i++)
        printf("  %d", i);
    printf("\n");
    for(i = 0; i < 10; i++){
        printf("%d ");
        for(q = 0; q < ndigit[i]; q++) {
            printf("|");
        }
        printf("\n");
    }



}
