#include <limits.h>
#include <float.h>
#include <stdio.h>
void check_data_types();

int main(int argc, char **argv){
    printf("CHAR MAX: %d\n", CHAR_MAX);
    printf("CHAR MIN: %d\n", CHAR_MIN);
    printf("FLOAT MAX: %f\n", FLT_MAX);
    printf("FLOAT MIN: %f\n", FLT_MIN);
    printf("INT MAX: %d\n", INT_MAX);
    printf("INT MIN: %d\n", INT_MIN);
    return 0;
}
