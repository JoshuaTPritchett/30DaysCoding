#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAXVAL 100
void itoa(int n, char t[]);
void reverse(char s[]);
void printd(int n);
void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);
void recursive_itoa(int n, int base);
void recursive_reverse(char t[], int first, int last);
/* itoa: low order digits are offered before high order digits */
/* IE 2014 4 then 1 then 0 then 2 mod 10 (or the base we want)
 *
 * Two solutions to this problem either store them in an array and reverse the array
 * like itoa does, or make a recursive call in which printd calls itself
 * cope with any leading digits then prints trailing digits
 */
void itoa(int n, char t[]) {
    int i, sign;
    sign = (n < 0) ? -1 : 1;

    i = 0;
    do {
        t[i++] = n % 10 + '0';
    } while((n /=10) > 0);

    if (sign  < 0)
        t[i++] = '-';

    t[i++] = '\0';
    reverse(t);
}


void recursive_itoa(int n, int base) {
    if (n < 0) {
        putchar('-');
        if ( n <= INT_MIN)
            n = -n -1;
        else
            n = -n;
    }

    ;
    if (n/base)
        recursive_itoa(n/base, base);

    switch (base) {
        case 8:
            printf("%c", n % base + '0');
            break;
        case 10:
            printf("%c", n % base + '0');
            break;
        case 16:
            (n % base < 9) ? printf("%c", n % base + '0') : printf("%c", (n % base - 10) + 'a');
            break;
        default:
            printf("error: invalid base value\n");
            break;

    }

}
void reverse_string(char s[], int first, int last) {
    void swap_2(char s[], int first, int last);
    if (first < last) {
        swap_2(s, first, last);
        reverse_string(s, ++first, --last);
    }
}
void swap_2(char s[], int first, int last) {
    int temp;

    temp = s[first];
    s[first] = s[last];
    s[last] = temp;
}
void printd(int n) {
    if (n < 0) {
        putchar('-');
        n = -n;
    }
    if (n/10)
        printd(n/10);
    putchar(n % 10 + '0');

}

void qsort(int v[], int left, int right) {
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)
        return;

    swap(v, left, (left + right)/2);
    last = left;

    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(int v[], int i, int j) {
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;;
}
void reverse(char s[]) {
    int c;
    unsigned int i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;

}
int main(int argc, char **argv) {
    char t[MAXVAL];
    int i;
    for (i = 'a'; i < 'q'; i++)
        t[i - 'a'] = i;
    t[i - 'a'] = '\0';
    printf("t before: %s\n", t);
    reverse_string(t, 0, strlen(t) - 1);
    printf("t after: %s\n", t);
    itoa(200, t);
    printf("string t: %s\n", t);

    printd(200);
    printf("\n");
    recursive_itoa(200, 10);
    printf("\n");
    recursive_itoa(200, 8);
    printf("\n");
    recursive_itoa(200, 16);
    printf("\n");
    return 0;
}
