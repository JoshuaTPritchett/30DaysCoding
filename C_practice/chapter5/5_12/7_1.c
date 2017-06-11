#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void upper_to_lower(char *);

int
main(int argc, char *argv[]) {
    char **a;
    char *b = malloc(sizeof(char) * 2);
    *b = 5;
    a = malloc(sizeof(char *) * 2);
    a[0] = b;
    if (a[0] == NULL)
        puts("whoops we fucked up");
    printf("everything worked!\r\n");
    printf("test value: %d \n", *b);
    if (argc >= 2)
        upper_to_lower(argv[1]);
    else
        printf("error: not enough arugments\n");
    return 0;
}

void upper_to_lower(char *s) {

    int c;
    while ((c = getchar()) != EOF) {
        if (strcmp(s, "upper") == 0)
            putchar(toupper(c));
        else
            putchar(tolower(c));
    }
}
