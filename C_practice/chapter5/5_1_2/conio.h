/*
 * File to mimic the functionality that is
 * provided within windows systems, this is
 * due to the fact that Linux does not provide
 * it's own implementation of getch() in for
 * the GCC compiler.
 */

#ifndef __CONIO_H__
#define __CONIO_H__


/* Gets a character from user intput */
int getch(void);
/*
 * Returns a character to a specified buffer
 * which then can be read at a later time
 */
void ungetch(int);
#endif
