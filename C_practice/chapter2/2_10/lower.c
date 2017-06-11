#include <stdio.h>
#include <ctype.h> //Used for lower function
int lower(int c);

int main(int argc, char **argv) {
    printf("lower difference %c\r\n", lower('A'));
    printf("lower %c\r\n", tolower('A'));
    return 0;

}

int lower(int c) {

    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}
