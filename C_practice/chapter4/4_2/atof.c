#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* Used for isspace and isdigit functions */

/* Consistent string value that will be used throughout the program  */
#define VALUE "1234"
#define VALUE_TWO "1234.5678e-10"


/* Function prototypes in order */
double my_atof(char s[]);
double my_atof_2(char s[]);
unsigned int count_bits_1(int val);
unsigned int count_bits_2(int val);

void print_notation_test(void);


/* Main function */
int main(int argc, char **argv) {

    double a = atof(VALUE);
    printf("A: %f\n", a);

    printf("B: %f\n", my_atof(VALUE));
    printf("C atof_2: %.14f\n", my_atof_2(VALUE_TWO));
    printf("bits 1: %u\n", count_bits_1(20));
    printf("bits %u\n", count_bits_2(20));
    printf("negative bits value: %u\n", count_bits_2(-20.2));
    printf("negative 20 in memory representation %x\n", -20.2);

//    print_notation_test();
    return 0;
}
void print_notation_test(void) {
    double i = 1.0;
    for (i = 1.0; i < 10000000; i *= 10)
        printf("%f\n", 1.0/i);
}
/*
 * count_bits_1: will
 *
 */
unsigned int count_bits_1(int val) {
    unsigned int bits;
    bits = 0;
    while (val != 0) {
        val >>= 1;
        if (val & 0x1)
            bits++;
    }
    return bits;
}
/*
 * count_bits_2: will count the number of bits within a given valued number
 * the number must be a non-floating point value
 *
 * Until the value reaches subtract one from the value
 * which will cause the value to remove the right most bit.
 *
 * For each iteration of the for loop the value has not had
 * all of the 1 bits removed. This is a slight improvment
 * in terms of the number of calculations versus the previous
 * count_bits_1 version.`
 */
unsigned int count_bits_2(int val) {
    unsigned int bits;

    /* Main for loop that will calculate the number of bits in a value */
    for (bits = 0; val != 0; bits++, val &= (val -1));
    return bits;
}

/*
 * my_atof_2: converts a string s to a double value
 *  S can now be in scientific format, most floats
 *  are represented as scientfic format or can be
 *  parsed as such
 */
double my_atof_2(char s[]) {
    double power, z;
    long double val, final_val;
    int sign, exponent_val, exponent;
    long long int q;
    unsigned int i; /* i will be used to traverse the string */

    /* Skip the spaces in the character string */
    for (i = 0; isspace(s[i]); i++);

    /* Get the sign that is in the chracters string */
    sign = s[i] == '-' ? -1 : 1;

    /* Skip the sign after testing */
    if (s[i] == '+' || s[i] == '-')
        i++;

    /* Compute the values before the fixed point */
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* Skip the fixed point decimal */
    if (s[i] == '.')
        i++;

    /*
     * Compute the value for the remaining digits
     * while keeping track of the power (exponent)
     * that is represented in the float. Start power
     * at 1 because a power cannot be zero.
     */
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0; /* Multiply out the power here */
    }

    /* Caluclate the final value */
    final_val = sign * val / power;

    /* Extended for scientific notation */
    if (s[i] == 'e' || s[i] == 'E')
        i++;

    /* Determine what the exponent values should be for the notation */
    exponent_val = (s[i] == '+') ? 1 : -1;
    if (s[i] == '+' || s[i] == '-') i++; /* skip the next positive or negative value */

    exponent = 0;
    while(isdigit(s[i])) {
        exponent = 10 * exponent + (s[i] - '0');
        i++;
    }
    for (z = 1.0, q = exponent; z < exponent; z++) {
        printf("q %lld\n", q);
        q = q * 10;
    }
    if (exponent_val > 0)
        final_val *= q;
    else
        final_val /= q;

    /* The power will be scaled expoentially */
    return final_val;
}


/* my_atof: converts string s to a double value, does not check for how large */
double my_atof(char s[]) {
    double val, power;
    int i, sign;

    /* Skip spaces */
    for (i = 0; isspace(s[i]); i++)
            ; /* skip spaces */

    /* Check for sign values only -1 is of interest */
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;

    /* Calculate the first half of digits before period */
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* Skip the . */
    if (s[i] == '.')
        i++;

    /* check for digits in the last part of the range */
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}
