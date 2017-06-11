#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 30 /* based on possibility of at least 64 -(2^(64-1)) */
void reset_char_arr(char s[]);
void itoab(int n, char s[], unsigned int base);
void itoa_signed(int n, char s[]);
void itoa_basic(int n, char s[]);
void reverse(char s[]);

int main(int argc, char **argv) {
    char s[MAX_ARR_SIZE + 1];
    int i = -90;
    reset_char_arr(s);
    itoa(200, s, 2);
    printf("itoa basic output %s\r\n", s);

    reset_char_arr(s);
    itoa_signed(INT_MIN, s);
    printf("itoa signed output %s\r\n", s);

    reset_char_arr(s);
    itoab(208, s, (unsigned int) 16);
    printf("itoab output %s\r\n", s);

    reset_char_arr(s);
    itoab(208, s, (unsigned int) 8);
    printf("itoab output %s\r\n", s);

    reset_char_arr(s);
    itoab(208, s, (unsigned int) 2);
    printf("itoab output %s\r\n", s);

    return 0;
}

void reset_char_arr(char s[]) {
    unsigned int i = 0;
    while (i < MAX_ARR_SIZE)
        s[i++] = '\0';

    s[i++] = '\0';

    return;
}


void itoab(int n, char s[], unsigned int base) {
    int i, sign, value;
    i = sign = 0;

    if ((sign = n) < 0){
        if (sign <= INT_MIN)
            n = -n - 1;
        else
            n = -n;
    }

    do {
        value = n % base;
        if (base == 16)
            s[i++] = ((value <= 9) && (value >= 0)) ? value + '0' : (value - 10) + 'a';
        else
            s[i++] = value + '0';
    } while ((n /= base) > 0);



    if (sign < 0)
        s[i++] = '-';

    /* Consider the base value */
    if (base == 16)
        s[i++] = 'x', s[i++] = '0';
    else if(base == 8)
        s[i++] = '0';

    s[i++] = '\0';
    reverse(s);

    return;

}

/* Has the ability to handle INT_MIN */
void itoa_signed(int n, char s[]) {
    int i, sign;
    i = sign = 0;

    if ((sign = n)  < 0) {
        if (sign <= INT_MIN)
            n = -n -1; /* converting sign to sign we have 2^(wordsize -1) - 1*/
        else
            n = -n;
    }

    do {
        s[i++] = n % 10 + '0'; /* take the remainder of the decimal and add 0 for offset */
    } while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    if (sign <= INT_MIN)
        s[0] += 1;

    /* Add null terminator */
    s[i++] = '\0';

    reverse(s);
    return;
}

void itoa_basic(int n, char s[]) {
    int i, sign;
    i = sign = 0;

    if ((sign = n) < 0) /* Check to see if value is negative */
        n = -n;

    do {
        /*
         * Perform modulo operation to convert down from 10
         * to get the remainder of the value from base 10
         */
        s[i++] = n % 10 + '0';
    } while((n /= 10) > 0);

    if (sign  < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);

    return;
}


void reverse(char s[]) {
    unsigned int i, c, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;

    return;
}
