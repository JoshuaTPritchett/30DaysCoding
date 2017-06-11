#include <stdio.h>
#include <ctypes.h>
/**
 * Language does not specify wheter variables of type char are
 * signed or unsinged
 *
 * Can a char converted to int ever produce negative value?
 *  Depends on machine to machine specifics
 *  Either it appends on 00s when upcasting
 *  or the leftmost bit is converted to 1 "sign extension"
 *
 *  C definition guarantees that character in standard character set will never be negative
 *  for portability specify signed or unsigned
 *
 *  Comparisons like i > j will return true
 *
 *  Some functions may return non-negative, but this doesn't matter
 *      IF while and others just check for 0 to be false
 *
 *
 */
int atoi(char s[]);

int main(int argc, char **argv) {
    int val = atoi("0132");
    printf("Val: %d\n", val);
    char c = tolower('C'); //portable conversion of char lower conversion
    return 0;
}

int atoi(char s[]) {
    int i, n;
    n = 0;
    for(i = 0; (s[i] >= '0' && s[i] <= '9') || isdigit(s[i]); ++i) {
        n = 10 * n + (s[i] - '0');
    }
    return n;
}
/* converts a char to lower case
 * Only works with ascii
 */
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}


