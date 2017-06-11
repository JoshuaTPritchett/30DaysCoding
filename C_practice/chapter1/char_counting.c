#include <stdio.h>
int main() {
    int nc = 0;
    long ncl = 0;
    float ncf = 0.0;
    double ncd = 0.0;
    while(getchar() != EOF) {
        nc++;
        ncl++;
        ncf++;
        ncd++;
    }

    //++nc prefix
    //nc++ postfix
    //int is at least 16 bits (2bytes)
    //long int is at least 32 bits(4 bytes)
    //float is at least 32 bits(4 bytes)
    //double is at least 64 bits(8 bytes)
    printf("%1d\n", nc);
    printf("%lu\n", ncl);
    printf("%1.1f\n", ncd);
    //printf uses %f for both float and double
    printf("%f", ncf);
    printf("%f", ncd);
    return 0;
}
