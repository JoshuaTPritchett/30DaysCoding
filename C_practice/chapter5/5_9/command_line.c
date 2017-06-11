/*
 * Lets do this stupid command line shit that is required by the book
 * LEARN C
 */
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#define MAXLINE 1000

void print_1(int argc, char *argv[]);
void print_2(int argc, char *argv[]);
int pattern_find(const char *s);
size_t my_getline(char *s, size_t size);

int
main (int argc, char *argv[]) {
    //print_1(argc, argv);
    //print_2(argc, argv);

    if (argc != 2)
        printf("Usage: find pattern\n");
    else
        pattern_find(argv[1]);
    return 0;
}

void
print_1(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    printf("\n");
}

/* since argv is a ponter we can manipulate it down */
void
print_2(int argc, char *argv[]) {
    while (--argc > 0)
        printf("%s%s", *++argv,  (argc > 1) ? " " : "");
    printf("\n");
}

int
pattern_find(const char *s) {
    char line[MAXLINE];
    int found = 0;
    while (my_getline(line, MAXLINE) > 0) {
        //strstr will return the first occurance of a value that is declared in <string.h>
        if (strstr(line, s) != NULL) {
            puts("found");
            printf("%s", line);
            found++;
        }
    }

    return found;
}


size_t my_getline(char *s, size_t size) {
    size_t i = 0;
    int c;
    char *p = &s[0];
    while (i < size && (c = getchar()) != EOF && c != '\n')
        *(p + i++) = c;

    printf("i value:%lu\n", i);
    if (c == '\n')
        *(p++) = c;
    *(p) = '\0';
    return strlen(s);
}
