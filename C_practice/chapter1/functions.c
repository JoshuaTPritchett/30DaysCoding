#include <stdio.h>
int power(int, int);
void convert_celc(int);

int main(int argc, char **argv) {
    int i;
    for(i = 0; i < 10; i++)
        printf("p1:%d , p2:%d\n", power(2, i), power(-3, i));

    convert_celc(320);
    return 0;
}

void convert_celc(int degrees) {
    int i;

    for(i = 0; i <= degrees; i+=20)
        printf("Far: %d,    Celc: %6.1f\n", i, (5.0/9) * (i - 32));
    return;
}
/*What the fuck! How old!
power(base, n)
int base, n; {
    int i, p;

}
*/

int power(int base, int n) {
    int i, p;

    p = 1;
    for(i = 1; i <= n; i++)
        p = p * base;

    return p;
}
