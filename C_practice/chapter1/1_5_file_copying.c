#include <stdio.h>


void original_func(void);
void new_func(void);

/**
 * Lets test with this file for character reading
 */
void
fgetc_func() {
    int c = fgetc(0);
    printf("%4d\t\n",c);
    printf("%c\t", c);

    return;
}


/**
 * Same as fgetc except it can be used in more than
 * on evaluation of a string
 *
 * @return void
 */
void
getc_func() {
    int c;
    // Question to ask is do we need stdin here?
    //  Answer: The passing parameter is set to 0
    //  due to the fact that 0=stdin
    while((c = getc(0)) != EOF)
        printf("%c", c);

    return;
}


void
new_func() {
    int c;

    // Base 10 is the common sytem for numbers
    // Thus,

    // cleaner more precise
    // != is higher PRESCEDENCE thank that of =
    // this != would complete before =
    while((c = getchar()) != EOF) {
        printf(" Octal ASCII");
        // getchar returns octal value
        printf("%4d\t", c);
        //cool idea print in char
        printf("%c", c);
        // putchar(c);
    }
    printf("%2.0f\n", EOF);
}


void
original_func() {
    int c;// must be big enough to handle EOF and char possible

    // Next char to take in stored as an integer type (bit pattern)
    c = getchar();
    while (c != EOF) {
        // EOF is defined as in int in stdio.h
        // Doesn't matter since are using an int
        // By using EOF assured nothing depends on numerical value
        putchar(c);
        //Returns distinctive value when no more input
        //Special value is EOF
        c = getchar();
    }

}
int main(int argc, char **argv) {
        new_func();
        return 0;
}
