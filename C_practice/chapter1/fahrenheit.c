#include <stdio.h>

//Symbolic constants <NAME> <VALUE>
#define HIGH 300
#define LOW 0
#define STEP 20


// Function prototypes
void symbolic_constant_check(void);
void reverse_order(int);
void new_conversion(int);
void calculate_f_for(int, int, int);

/**
 * Function will replace important elements
 */
void
symbolic_constant_check(void) {
    int far = 0;
    for(far = 0; far <= HIGH; far += STEP)
        printf("%3d\t%6.1f\n", far, (5.0)/(9) * (far - 32));

}

void
reverse_order(int high) {

    int far = 0;
    for(far = high; far >= 0; far-=20)
        printf("%3d\t%6.1f\n", far, (5.0/9) * (far - 32));
}


/** Function will use for loop to print the
 *  required sequence of numbers
 *
 *  @param int high the highest value of F we want
 *  @return void
 */
void
new_conversion(int high) {

    int farenheight;
    for(farenheight = 0; farenheight <= high; farenheight+=20)
        printf("%3d\t%6.1f\n", farenheight, (5.00/9.0) * (farenheight-32));

}

void
calculate_f_for(int low, int high, int step) {
    int i = low;
    int cel = 0;
    float original = 5/9;
    float division_fix = 5/9.0; //one float integer will convert
    for(; i <= high; i+=step) {
        /* 5/9 has integer truncation */
        cel = division_fix *(i-32);
        printf("%3d\t%6.1f\n", i, cel);
        // 3 digits wide
        // 6 digits wide
        // 3.0:
    }
    return;
}



int
main(int argc, char **argv) {
    int low = 0;
    int high = 300;
    int step = 20;
    calculate_f_for(low, high, step);
    new_conversion(high);
    reverse_order(high);
    symbolic_constant_check();
    return 0;
}
