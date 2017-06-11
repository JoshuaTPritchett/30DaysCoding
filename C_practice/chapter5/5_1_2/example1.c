#include <stdio.h>
#include "test.h"

void test(void);
void stupid_pointer_shit(void);
int
main (int argc, char *argv[]) {

    test();
    return 0;
}
/* test function that will call the get int call */
void test() {
   //test_getint();
   test_getfloat();
}

/* stupid_poni: YEAH FUCK IT POINTERS>!>!>!>! */
void stupid_pointer_shit() {
    int x = 1, y = 2, z[10];
    int *ip; /* ip is a pointer to int */


    /* Declare values in the z array */
    unsigned int i;
    while (i < 10)
        z[i++] = i;

    ip = &x; /* ip points to x */
    printf("Address of ip %p\n", ip);
    printf("Address of x: %p\n", &x);
    printf("ip value; %d\n", *ip);
    printf("x value: %d\n", x);

    y = *ip; /* y is now 1 or the value of x */
    printf("y value: %d\n", y);

    *ip = 0; /* x is now 0 */
    printf("ip value; %d\n", *ip);
    printf("x value: %d\n", x);

    /* Interesting changing the value of IP does not change the value of y */
    printf("y value: %d\n", y);

    z[0] = 20;
    ip = &z[0]; /* ip now points to z[0] */

    printf("Address of ip %p\n", ip);
    printf("Address of x: %p\n", &x);
    printf("ip value; %d\n", *ip);
    printf("x value: %d\n", x);

    int *iq;

    iq = ip;

    printf("Address of ip %p\n", ip);
    printf("Address of iq %p\n", iq);
    printf("Value of ip %d\n", *ip);
    printf("Value of iq %d\n", *iq);


    *ip = 4;
    printf("Value of ip %d\n", *ip);
    printf("Value of iq %d\n", *iq);

    /* Since they both point to the same memory location they can each modify the value */
    *iq = 5;
    printf("Value of ip %d\n", *ip);
    printf("Value of iq %d\n", *iq);

    int t1 = 1, t2 = 3;
    swap(&t1, &t2);
    printf("Value of t1 %d\n", t1);
    printf("Value of t2 %d\n", t2);
    printf("Address of t1 %p\n", &t1);
    printf("Address of t2 %p\n", &t2);



    incorrect_swap(&t1, &t2);
    printf("Value of t1 %d\n", t1);
    printf("Value of t2 %d\n", t2);
    printf("Address of t1 %p\n", &t1);
    printf("Address of t2 %p\n", &t2);


}

