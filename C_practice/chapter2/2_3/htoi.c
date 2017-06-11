#include <stdio.h>
#include <math.h>
int htoi(char s[]);
int my_strlen(char s[]);


int main(int argc, char **argv) {
    unsigned long int val;
    val = htoi("0x4E"); //Check A
    if (val > 0)
        printf("Value val: %lu", val);
    else
        printf("improperly formatted");
    printf("Octal conversion: %c\n", 0101);
    return 0;
}


int htoi(char s[]) {
    int i, j;
    unsigned long int z;
    i = z = 0;
    j = my_strlen(s) - 1;

    if(j < 2) return z;
    if (s[i++] != '0') return z;
    if (s[i] != 'X' && s[i] != 'x') return z;

    //reset to make sure it's good
    i = 0;
    //Convert hexidecimal to integer
    for(i = 0; s[j] != 'x' && s[j] != 'X'; j--, i++) {
        if(s[j] >= '0' && s[j] <= '9')
            z =  z + (s[j] - '0') * pow(16, i);
        else if(s[j] >= 'a' && s[j] <= 'f')
            z = z + ((s[j] - '0') + 1) * pow(16, i);
        else if(s[j] >= 'A' && s[j] <= 'F')
            z = z + ((s[j] - 'A') + 10) * pow(16,i);
        else
            continue;
    }
    return z;
}
int my_strlen(char s[]) {
    int i = 0;
    //make an assumption to simplify problem that it is formatted correctly
    while(s[i] != '\0')
        i++;
    //assumption made due to the first to 0x or 0X we can error handle later
    return i;
}
