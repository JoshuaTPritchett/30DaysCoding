/*
 * My own stupid implementation of getch() and ungetch()
 * since they don't exist within Linux and I need them
 * to read this fucking book K&R <3
 *
 * @author Joshua T. Pritchett
 */
#include <stdio.h>
#include "conio.h"

/* We will accept 100 total characters into the buffer */
#define BUFFSIZE 100
static int buffp = 0;
static int buff[BUFFSIZE];


/*
 * getch: will check the buffer for any addtional characters
 * that were pushed back out for output, at most we should
 * mostly just have one character to deal with. We are going
 * to only focus on user input in this case.
 *
 * @return int character that was return to be read from the buffer
 */
int getch() {
    return (buffp > 0) ? buff[--buffp] : getchar();
}

/*
 * We have read too many arguments then we should put the character
 * back within a buffer to be read.
 * 1) Check the size of the buffer, if it is full then print an error
 * 2) If the buffer is not full then place the character back in the buffer
 *
 * @param int c the character to be placed back in the buffer pool
 * @return void
 */
void ungetch(int c) {
    if (buffp > BUFFSIZE)
        printf("error: there are too many characters in the buffer\r\n");
    else
        buff[buffp++] = c;
}
