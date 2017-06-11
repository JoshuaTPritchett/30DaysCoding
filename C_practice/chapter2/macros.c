/**
 * Bruh were gonna get fuckin weird with some macros shit
 * Saves time by the compiler from invoking or calling functions
 * No time is taken by passing control to new function
 *  Control never leaves home function
 *
 *  Parens guarantee order of operation
 */

#include <stdio.h>


/**
 * Object like macros
 */
#define BUFFSIZE 100
#define TEMPBUF BUFFSIZE
#undef BUFFSIZE
#define BUFFSIZE 200

#define NUMS 1, \
             2, \
             3, \
             4
/**
 * Function based macros
 */
#define squared(x) x*x
/**
#undef squared
#define squared(x) (x*x)
#undef squared
#define squared(x) (x)*(x)
*/
#define min(x,y) (x < y) ? x : y


/**
 * Stringizing? # replaces with the literal text of the argument
 */
#define convstr(s) str(s)
#define str(s) #s //# is the literal to replace
#define FOO 4


#define WARN_IF(TEST) \
    do { \
        if(TEST) \
            printf("Warning: " #TEST "\n"); \
    }\
    while(0)
//^ Kludge (quick and dirty solution) to make this macro work



/**
 * Concatenation
 *  Merge two tokens while expanding macros
 *      Token pasting or token concatentation
 *      ## performs pasting
 *      Replaces ## with two original tokens in macro expansion
 *      can concatenate two numbers 1.5 + e3
 *      and += (multi-character operator)
 *      *** DO NOT concatenation x with + in either order
 */
void quit_command(void);
void help_command(void);


struct command {
    char *name;
    void (*function) (void);
};
struct command commands[] = {
    { "quit", quit_command},
    { "help", help_command}
};

//Can be redone as
//this is cool!
#define COMMAND(NAME) {#NAME, NAME ## _command}
struct command commands_2[] = {
    COMMAND(quit),
    COMMAND(help)
};

/**
 * Variadic macros any number of arguments after __VA_ARGS__
 * becomes the functions variable argument
 *
 * VA is completely macros expanded before inserted into macro
 *
 */
#define mprintf(...) printf(__VA_ARGS__)
#undef mprintf

//If it is complicated name the var args value
#define mprintf(args...) printf(args)
//Developer now must supply an argument after function
#undef mprintf
//Must now use comma after args
#define mprintf(fstring, ...) printf(fstring, __VA_ARGS__)

int main() {
    int a[] = {NUMS};
    // -> int a[] = {1,2,3}
    int i;
    for(i = 0; i < sizeof(a)/sizeof(a[0]); i++)
        printf("value in nums: %d\n", a[i]);
    printf("Test values: %d\n" , squared(2+1));
    printf("The min value %d\n", min(1,2));
    //

    printf("TEMP BUFF: %d\n", TEMPBUF);
    // -> BUFFSIZE 100
    // -> TEMPBUF 100
    // -> BUFFSIZE undef
    // -> BUFFSIZE 200
    // -> TEMPBUF 200


    printf("Min weird ass shit: %d\n", min(min(1,2), 3));
    // Macros first must expand all inside macros
    // So -> min((1) < (2) ? 1 : 2), 3)
    // -> (((1) < (2) ? (1): (2)) < (3) ? ((1) < (2) ? (1) : (2)) : (3))


    printf("Conversion value %s\n", convstr(FOO));
    // -> convstr(FOO)
    // -> str(FOO)
    // -> "4"
    int x = 0;
    WARN_IF(x == 0);

    mprintf("Hello world!",);
    return 0;
}
void quit_command(void) {
    printf("QUIT COMMAND\n");
    return;
}
void help_command(void) {
    printf("HELP COMMAND\n");
    return;
}
