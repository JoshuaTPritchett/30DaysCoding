/**
 * New function called getline() to read input
 *  Returns signal about EOF
 *  It's singal which is the length of returned line
 *  ZERO if EOF or Length of line
 *  Every line has length 1 even line with new line
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINE 500 /* MAX number of input lines */

int my_getline(char line[], int maxline);
int remove_blanks_tabs(char from[]);
void copy(char to[], char from[]);
void reversal(char from[], int len);


int
main() {
    int len;
    int max;
    char line[MAXLINE]; // current line to be had
    char longest_line[MAXLINE];
    len = max = 0;
    //Bounds check on length of line
    //getline checks for overflow
    //len should always return at least 1
    while((len = my_getline(line, MAXLINE)) > 0) {
        if (len == 1) {
            puts("We have encountered a new line");
            continue;
        }
        if (len < 80) {
            len = remove_blanks_tabs(line);
            printf("remove spaces and tabs: %s\n", line);
        }
        if (len > 80) {
            printf("The input was super long\n");
            printf("length of input %d\n", len);
        }
        if (len > max) {
            puts("longer than max");
            max = len;
            copy(longest_line, line);
        }
        reversal(line, len);
        //printf("Reversed string %s", reverse_string);
        memset(line, '\0', MAXLINE);
    }


    return 0;
}
//Length is not nessecary because we know from MAIN
int my_getline(char s[], int lim) {
    int c, i;

    //Bounds check on the limit - 1 (length of array + '\0')
    //Check for EOF in the input array
    //Check for new line
    //Success get the charater from input
    //supports removal of trailing blanks or tabs
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    //Reached new line copy into buffer
    //Return length of line
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    //Set last element = '\0'
    s[i] = '\0';
    if(s[i] == '\0')
        printf("empty PLACED\n");
    return i;
}

/**
 * Will not only remove the inner spaces, but will
 * also remove the spaces within the buffer itself
 *
 */
int remove_blanks_tabs(char from[]) {
    int i, z;
    i = 0;
    z = -1;
    if (strlen(from) == 0 || strlen(from) == 1)
        return strlen(from);

    printf("From original %s", from);
    while(from[i] != '\0') {
        if (z == -1 && (from[i] == ' ' || from[i] == '\t')) {
            z = i;//place holder
            printf("empty place found: %d\n", z);
        }
        else if (z > -1 && from[i] != ' ' && from[i] != '\t'){
            from[z] = from[i];
            from[i] = ' ';
            z = -1;
        }
        i++;
    }

    i = 0;
    z = 0;
    //remove trailing spaces
    while(from[i] != '\0') {
        if (from[i] == '\t' || from[i] == ' ') {
            z++;
            from[i] = '\0';
        }

        i++;
    }

    printf("I value: %d\n", i-z);
    return i - z;
}
void copy(char to[], char from[]) {
    int i = 0;
    //Copies the original value array into new array
    //Assumes that to can hold all of from
    while((to[i] = from[i]) !=  '\0')
        ++i;
    to[i] = '\0';
}

void reversal(char from[], int len) {
    size_t i = 0;
    size_t l = len - 2;
    printf("LEN: %d\n", len);
    char temp = '\0';
    while(i < l) {
        temp = from[l];
        from[l] = from[i];
        from[i] = temp;
        i++; l--;
    }
    from[len - 1] = '\0';
    printf("REVERSED: %s\n", from);
}
void normal_getline() {
    int len = 0;
    char *line_1 = NULL;
    long unsigned int size = 0;
    while((len = getline(&line_1, &size, stdin)) > 0) {
        printf("len %d\n", len);
        if (strstr(line_1, "\n"))
            printf("forces new line");
    }
    if (line_1 != NULL) {
        puts("freeing mem");
        free(line_1);
    }
}
