
#include "mystdlib.h"
#define ALLOCSIZE 1000


static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n) {
    /* Take the starting address of the buffer, add the size, subtract how much we need */
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* Indicate that it fits */
        allocp += n;/* Allocate the proper amount */
        return allocp - n; /* return the old pointer memory address where new value will start */
    } else
        return 0;
}
void afree(char *p) {
    /* make sure that the pointer is within the bounds of the array
     * greate or equal than the starting point and less than the total size */
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

