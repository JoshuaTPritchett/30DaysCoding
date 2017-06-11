#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "definitions.h"

#define MAXLINES  5000/* max number of lines to be sorted */
static char *lineptr[MAXLINES];

int get_input() {
    int nlines;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort1(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort \n");
        return 1;
    }
}

#define MAXLEN 1000 /* Max length of any input line */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline1(line, MAXLEN)) > 0) {
        if ((nlines >= maxlines) || (p = malloc(sizeof(char) * len)) == NULL)
            return -1;
        else {
            strcpy(p, line);/* strcpy should copy the null terminator */
            lineptr[nlines++] = p;
        }
    }
    writelines(lineptr,nlines);
    return nlines;
}
void writelines(char *lineptr[], int nlines){
    int i;
    puts("writing lines");
    printf("number of lines %d\n", nlines);
    while (--nlines >= 0)
        printf("%p: %s\n", lineptr, *lineptr++);

    puts("done writing lines");
}


int getline1(char *line, int size) {
    int i = 0, c;
    char *s = &line[0];
    while ((i  < size) && (c = getchar ()) != EOF && c != '\n')
        *s++ = c, i++;
    if (c == '\n')
        *s++ = c, i++;
    *s = '\0';
    return i;
}
