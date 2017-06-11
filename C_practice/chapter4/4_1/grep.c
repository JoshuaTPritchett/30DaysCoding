#include <stdio.h>
#define MAXLINE 1000


int my_getline(char line[], int size);
int rightmost_strindex(char s[], char t[]);
int strindex(char source[], char searchfor[]);


char pattern[] = "ould";

int main(int argc, char **argv) {

    char line[MAXLINE];
    int found = 0, right_most = 0;
    while (my_getline(line, MAXLINE) > 0)
        if ((right_most = rightmost_strindex(line, pattern)) >= 0) {
            printf("%s", line);
            printf("right most index %d\n", right_most);
            found++; /* Determines the number of lines with the matched pattern */
        }
    return found;
}


/* getline: get line into s, return length */
int my_getline(char s[], int size) {
    int c, i;

    i = 0;
    while ( --size > i && ((c = getchar()) != EOF)  && c != '\n')
        s[i++] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}


int rightmost_strindex(char s[], char t[]) {

    int j, k, right_most, i;

    right_most = -1;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; k++, j++)
            ;
        if (t[k] == '\0' && k > 0)
            if (i > right_most)
                right_most = i;
    }
    return right_most;
}
/*
 * strindex: returns the index of t in s, -1 if none
 *  Since arrays start at either 0 or positive then
 *  -1 is a good indicator of not finding an index
 *  searching through a given array
 *
 *  Standard way to search a string is strstr
 *  this returns a pointer versus an index
 * */
int strindex(char s[], char t[]) {

    int i, j, k;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; s[j] != '\0' && s[j] == t[k]; j++, k++)
            ;

        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
