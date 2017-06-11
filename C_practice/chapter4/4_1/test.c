#include <stdio.h>
int main(int argc, char **argv) {
    int val = 0777;
    printf("val2: %x\r\n", ~0);
    printf("val1: %x\r\n", ~0 >> 8);
    printf("VALUE: %x\r\n", (((val & 0xFF) << 8) | (val >> 8)));
    return 0;
}
