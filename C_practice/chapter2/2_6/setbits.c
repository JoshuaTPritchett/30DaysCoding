/*
 * Full disclosure this is a learning file so I can teach
 * myself bit shfiting
 *
 * @author Joshua T. Pritchett
 */
#include <stdio.h>


/* Define true and false values */
#define TRUE 1
#define FALSE 0

/* Will shift the bits from p to m */
unsigned int getbits(unsigned int x, int p, int n);

/* Turnsthe right most bits from x into y */
unsigned int set_bits(unsigned int x, int p, int n, unsigned int y);

/* Inverts a given range of bits */
unsigned int invert(unsigned int x, int p, int n);

/* Shifts a value to the right */
unsigned int rightmost(unsigned int x, int n);


int main(int argc, char  **argv) {
    unsigned int x = 240;
    printf("X base value: %d\n", x);
    printf("X with the value reversed : %d\n", ~8);
    printf("X with the value reversed : %d\n", 6 >> 2);
    printf("X value with 2 shift: %d\n", 240 >> 2);
    printf("X value with 0 inverse: %d\n", (unsigned int) ~(~0 << 3));
    printf("60 & 7: %d\n", (unsigned int) 60 & 7);
    printf("Value of 240 shifted: %d\n", 240 >> (4 + 1 - 3));
    printf("240 with zero shift: %d\n", 240 >> 0);

    /* Let's get fucking weird */
    printf("X value after shift: %d\n", getbits(240, 4,3));
    x = 65520;
    unsigned int y = 15;
    printf("Set bits x to n rightmost of y : %hu\r\n", set_bits(x, 4, 4, y));
    x = 43690;
    printf("Inverted value of X: %d\r\n", invert(x, 8, 3));

    x = 2863311535;
    printf("Right rotated of x: %x\r\n", rightmost(x, 4));
    return 0;
}


unsigned int getbits(unsigned int x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}


/*
 * Retruns x with the n bits that begin at position p set
 * to the rightmost n bits of y, leaving other bits unchanged
 */
unsigned int set_bits(unsigned int x, int p, int n, unsigned int y) {
    /* Condensed version */
    return ((~0 << (p - (p-n))) & x) | (y & (~0 >> (p + (p-n))));
}


/*
 * Returns x with the n bits that begin at position p
 * inverted (i.e. 1 changed into 0 and vice versa),
 * leaving the others unchanged
 */
unsigned int invert(unsigned int x, int p, int n) {
    /* First we must slide the masking bits to get only the required range */
    unsigned int mask = (~0 << (p + (p - n)));

    /*
     *  Next we must take the ones compliment of this
     *  which will allow us to perform the right shift
     */
    mask = ~mask;

    /*
     * We right shift by the position to place just the four we need,
     * we will do this by shifting back the original left shift
     */
    mask >>= p + ((p-n) - n);

    //Lef
    mask <<= p - n;

    /* Finally, we will take the xor to swap the bits in place */
    x ^= mask;

    return x;
}

/*
 * Rightmost will rotate an integer x by n positions
 */
unsigned int rightmost(unsigned int x, int n) {
    unsigned int mask = ~(unsigned int)0;
    mask <<= (sizeof(mask) * 8) - n;
    printf("Hex of mask %x\r\n", mask);
    mask  = ~mask;
    printf("Swapped of mask: %x\r\n", mask);
    mask >>= (sizeof(mask) * 8) - (n * 2); //for offset of original n
    printf("right shift mask: %x\r\n", mask);
    mask &= x;
    printf("and value of mask: %x\r\n", mask);
    mask <<= (sizeof(mask) * 8) - n; // Shift back to original spot
    printf("shift back of mask: %x\r\n", mask);
    //Shift x
    x >>= n;
    printf("right rotation of x: %x\r\n", x);
    x |= mask;
    printf("X: %x, mask: %x", x, mask);
    return x;
//    printf("Mask: %x\r\n", mask >> n); Dude what the total fuck
//    printf("Mask: %x\r\n", mask >> (unsigned int)n);
}


/*
 * Just ignore this stupid shit
 */

/*Shit none of this worked because it was saving all of the values
    //Change this and make it work
    usigned int q = ~x;
    printf("Q value: %hu\r\n", q);
    q <<= p + (p - n);
    printf("Q value: %hu\r\n", q);
    printf("PN value: %hu\r\n", p + (p+n));
    unsigned int test = 0;
    test = q ^ test;
    printf("Test value: %hu\r\n", test);
    printf("Test value: %hu\r\n", test >> 6);
    return q ^ x;
    */

