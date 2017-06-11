#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
void bubble_sort(int  *arr, size_t size);
void swap(int *arr, int i, int j);
void minprintf(char *fmt, ...);
void test_printing();
void calculate();
void getline_test(void);
char *my_fgets(char *s, int n, FILE *iop);
int my_fputs(char *s, FILE *iop);
int my_getline(char *line, int max);



int
main(int argc, char *argv[]) {
    int arr[] = {4, 3, 2, 1};
    bubble_sort(arr, 4);
    size_t i;
    for (i = 0; i < 4; i++)
        printf("%d -> ", arr[i]);

    printf("END\n");
    test_printing();
    minprintf("%d\n", 1);
    minprintf("test %Lf\n", 1.0L);
    ///calculate();
    getline_test();
    return 0;
}



void
minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    long unsigned int luval;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                printf("%d", va_arg(ap, int));
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                for (sval = va_arg(ap, char *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'l':
                ++p;
                if (*p == 'u')
                    printf("%lu", va_arg(ap, long unsigned int));
                break;
            case 'L':
                ++p;
                if (*p == 'f')
                    printf("%Lf", va_arg(ap, long double));
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap); /* Clean up the list when done */
}


/* Seems to be primarly Posix 2008 compliant */
void
getline_test() {
    char *buff = malloc(sizeof(char *) * 20);
    size_t size = 20;
    size_t i = 0, len;
    while ((len = getline(&buff,  &size, stdin)) > 1)
        printf("%s\n"
                "%lu\n", buff, len);

}

char *
my_fgets(char *s, int n, FILE *iop) {
    register int c;
    register char *cs;

    cs = s;
    while (--n > 0 && (c = getc(iop)) != EOF)
        if ((*cs++ = c) == '\n')
            break;

    *cs = '\0';
    return (c == EOF && cs == s) ? NULL : s;
}


int
my_fputs(char *s, FILE *iop) {

    register int c;
    while (c = *s++)
        putc(c, iop);
    return ferror(iop) ? EOF : 0;
}

/* stupid getline method */
int
my_getline(char *line, int max) {
    if (my_fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);
}

/* shit I wanna code bubble short where we go */
void
bubble_sort(int *arr, size_t size) {
    int n;
    size_t i;
    while (size > 0) {
        for (i = 1; i < size; i++) {
            if (arr[i - 1] > arr[i])
                swap(arr, i - 1, i);

        }
        --size;
    }
}

void
swap(int *arr, int i, int j) {
    int temp;
    temp   = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void
test_printing() {

    char *s = "Hello world";

    /*
     * %width.length for format specifiers of printing in C
     * Negative will be left justified
     */
    printf("%10.4s \n",s);
    printf("%-10.4s \n", s);
    return;
}

void
calculate() {
    int num, total = 0;
    while (scanf("%d", &num) ==  1) {
        total += num;
    }
    printf("%d\n", total);
    return;
}
