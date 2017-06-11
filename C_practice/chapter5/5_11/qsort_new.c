#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void my_qsort(void *lineptr[], int left, int right,
            int (*comp)(void *, void *));

void swap(void *v[], int, int);

int numcmp_inc(const char *, const char *);
int numcmp_dec(const char *, const char *);
int my_strcmp(const char *, const char *);
int fold_strcmp(const char *, const char *);

int
main(int argc, char *argv[]) {
    int nlines;
    int numeric = 0, reverse = 0, fold = 0;
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if (argc > 1 && strcmp(argv[1], "-f") == 0)
        fold = 1;
    if (argc > 2 && strcmp(argv[2], "-r") == 0)
        reverse = 1;
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        /* generic pointer type void * can be used for pointer arguments */
        /* any pointer can be cast to void *, and back without loss */
        my_qsort((void **)lineptr, 0, nlines -1,
                (int (*)(void *, void *))
                (numeric ? (reverse ? numcmp_inc : numcmp_dec) :
                    (fold ? fold_strcmp : strcmp))
        );
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
    for (size_t i = 0; i < nlines; i++) {
        free(lineptr[i]);
        lineptr[i] = NULL;
    }

    return 0;
}

void my_qsort(void *v[], int start, int end, int (*comp)(void *, void *)) {
    int i, last;
    if (start >= end)
        return;
    /*Pivot element */
    swap(v, start, (start + end) / 2);
    last = start;
    for (i = start + 1; i <= end; i++)
        if ((*comp)(v[i], v[start]) < 0)
            swap(v, ++last, i);
    swap(v, start, last);
    my_qsort(v, start, last - 1, comp);
    my_qsort(v, last + 1, end, comp);
}

void swap(void *v[], int q, int z) {
    void *temp;
    temp = v[q];
    v[q] = v[z];
    v[z] = temp;
}

int numcmp_inc(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int numcmp_dec(const char *s1, const char *s2) {
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 > v2)
        return -1;
    else if (v1 < v2)
        return 1;
    else
        return 0;
}



int my_strcmp(const char *s1, const char *s2) {
    for (;*s1 == *s2; s1++, s2++)
        if (*s1 == '\0')
            return 0;
    return *s1 - *s2;
}

int fold_strcmp(const char *s1, const char *s2) {
    size_t s1_len = strlen(s1), s2_len = strlen(s2);
    char *p1 = malloc(sizeof(char) * (s1_len + 1));
    char *p2 = malloc(sizeof(char) * (s2_len + 1));
    strncpy(p1, s1, s1_len);
    strncpy(p2, s2, s2_len);
    p1[s1_len] = '\0';
    p2[s2_len] = '\0';

    for (size_t i = 0; *(p1+ i) != '\0'; i++)
        *(p1 + i) = tolower(*(p1+i));
    for (size_t i = 0; *(p2 + i) != '\0'; i++)
        *(p2 + i) = tolower(*(p2 + i));

    int val = strncmp(p1, p2, (s1_len < s2_len ? s1_len : s2_len));
    free(p1), free(p2), p1 = NULL, p2 = NULL;
    return val;
}


#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    size_t line_len;
    char *p, *line;
    line_len = MAXLEN, nlines = 0;
    line = malloc(sizeof(char) * 1000);
    while ((len = getline(&line, &line_len, stdin)) > 0)
        if (nlines >= maxlines || (p = malloc(sizeof(char) * len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    free(line);
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
