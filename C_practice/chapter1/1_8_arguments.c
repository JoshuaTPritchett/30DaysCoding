/** Arguments are call by value (CBV)
 *  called function gets temporary variables
 *  Fortran/Pascal use Call by Reference (routine has access to original)
 *  CAlled function CANNOT alter a variable in function
 *      Only private temp copy
 */
#include <stdio.h>

#define HIGH 10

int
power(int base, int n) {

    int p;
    for(p = 1; n > 0; --n)
        p = p * base;
    return p;
}

int
main(int argc, char **argv) {
    int i;
    for(i = 0; i < HIGH; i++)
        printf("%d, %d\n", power(2, i), power(-3, i));
    return 0;
}
