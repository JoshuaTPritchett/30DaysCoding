#include <stdio.h>
#include <string.h>
#include <stddef.h>
#define MAXLINE 1000

size_t my_getline(char *line, int max);


int
main(int argc, char *argv[]) {
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (my_getline(line, MAXLINE) > 0) {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except) {
                if (number)
                    printf("line no: %ld\n", lineno);
                printf("line: %s\n", line);
                found++;
            }
        }
}

size_t my_getline(char *line, int max) {
    size_t i;
    int c;
    char *s = &line[0];
    for (i = 0; i < max && (c = getchar()) != EOF && c != '\n'; i++)
        *(s++) = c;
    if (c == '\n')
        *(s++) = c;
    *s = '\0';
    return strlen(line);
}


