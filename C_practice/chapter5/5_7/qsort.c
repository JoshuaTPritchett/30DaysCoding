#include <string.h>
#include <stdio.h>
#include "definitions.h"

void qsort1(char *lineptr[], int start, int end) {
    int i, last_visited;
    puts("Starting sorting process...");
    if (start >= end) /* there are two elements and we don't need to worry */
        return;

    /* Select the pivot we wish to choose */
    /* We will choose start in this case  */
    swap(lineptr, start, (start + end) / 2);

    /* Set the inital pivot at the start */
    last_visited = start;

    /* Iterate through the rest of the array and compare values from pivot */
    for (i = last_visited + 1; i <= end; i++)
        /* Compare the pivot position and the current position in the array */
        if (strcmp(lineptr[i], lineptr[start]) < 0) {
            /* Swap the last value that must be swapped with the value in the array */
            swap(lineptr, ++last_visited, i);
        }

    /* Once complete then swap the pivot position, and the start position */
    swap(lineptr, start, last_visited);

    /* Perform this on all sub arrays decreasing by one each time */
    qsort1(lineptr, start, last_visited - 1);
    qsort1(lineptr, last_visited + 1, end);
}

/* swap: interchages values (pointers that point) to dynamic values */
void swap(char *lineptr[], int pos1, int pos2) {
    char *temp;
    temp = lineptr[pos1];
    lineptr[pos1] = lineptr[pos2];
    lineptr[pos2] = temp;

    /* this in the long run will greatly reduce overhead */

}
