#include <stdio.h>
#include <string.h> //strlen and other string functions

enum boolean { NO, YES }; //first value 0, next 1....
//example months
enum months { JAN, FEB, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

//Names must be distinct however nums for the values do not need
//to be distinct
enum escapes{ BELL = '\a', BACKSPACE = '\b', TAB = '\t', NEWLINE = '\n', VTAB = '\v', RETURN = '\r' };
// Enum values are generated for me
// compliers do not need to check if a variable is a valid value
// enum allows the chance for checking and are better than #defines
// A debugger can print the values of enumation variables


int my_strlen(char a[]);

int main(int argc, char **argv) {
    char a[] = {'H','E','L','L', '\0'};
    int len = my_strlen(a);
    printf("Length of the string: %d", len);
    len = strlen(a);
    printf("Length of the string: %d", len);


    return 0;
}

int my_strlen(char a[]) {
    int i = 0;
    while(a[i] != '\0')
        i++;
    return i;
}
