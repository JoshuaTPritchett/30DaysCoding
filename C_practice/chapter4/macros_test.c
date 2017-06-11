#include <stdio.h>
#include <string.h>

#define max(A, B)  ((A) > (B) ? (A) : (B))

#define swap(T, X, Y) \
    if (T == sizeof(float)) { \
        float q = X, z = Y, w; \
        printf("q: %f, z: %f\n", q, z);\
        w = q;\
        q = z;\
        z = w;\
        printf("q: %f, z: %f\n", q, z);\
    }


int main(int argc, char *argv[]) {
    int q = 1;
    int z = 2;
    int x = max(q+1, z+1);
    printf("x value %d\n", x);
    swap(sizeof(float), 1, 2);
    return 0;
}
