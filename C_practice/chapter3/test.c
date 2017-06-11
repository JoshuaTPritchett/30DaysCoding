#include <stdio.h>
#include <stdint.h>
enum escapes{s0 = 0, s1=3, s2};
int last_three_bits(int val);
int problem_three_one(int x, int mask);
int problem_three_two(int, int, int);
int problem_three_three(int, int, int);

int main(int argc, char **argv) {
    int a = 0x1;
    printf("hel""lo");
    enum escapes test = s0;
    printf("s0 %d\n", test);
    test = s1;
    printf("s1 %d\n", test);
    test = s2;
    printf("s2 %d\n", test);
    int val = 0xCAFE;
    int v1 = val & 0xFF00;
    int v3 = v1 >> 8;
    int v2 = val & 0x00FF;

    printf("sixteen: %x\r\n", (((val & 0xFF00)) >> 8) | ((val & 0x00FF) << 8));
    //0x00FF not needed for last half because it's left  shift
    printf("last three bits %d\n", last_three_bits(val));
    printf("p3_1 : %d\n", problem_three_one(0xFF33, 0xFF00));
    printf("p3_2 : %d\n", problem_three_two(10,2,2));
    printf("p3_3 : %d\n", problem_three_three(10,2,1));

    printf("hex 0xf %d", 0xF);
    printf("Test two %d", 0xF000);
    return 0;
}
int last_three_bits(int val) {
    return ((val & 0xE) == 0xE000);
}
int problem_three_one(int x, int mask) {
    int c;
    return c=x && mask == 0;
}


int problem_three_two(int x, int y, int z) {
    return z=y=x++ + ++y*2;
}

int problem_three_three(int x, int y, int z) {
    return y>>= x & 0x2 && z;
}


