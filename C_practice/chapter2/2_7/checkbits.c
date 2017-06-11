#include <stdio.h>


unsigned int check_bits(unsigned int x);
unsigned int faster_check_bits(unsigned int x);



int main(int argc, char **argv) {
    printf("Number of bits: %hu\r\n", check_bits(10));
    printf("Number of bits faster: %hu\r\n", faster_check_bits(10));
    return 0;

}
unsigned int faster_check_bits(unsigned int x) {
    unsigned int bits;
    for(bits = 0; x != 0; bits++, x &= (x-1));
    return bits;
}
unsigned int check_bits(unsigned int x) {
    unsigned int bits;
    for(bits = 0; x != 0; x >>= 1)
        if(x & 01)
            bits++;
    return bits;
}
