#include <stdio.h>
#define MAX_CHAR 6

void squeeze(char s[],char t[]);
void my_strcat(char s[], char t[]);
int any(char s[], char t[]);

int main(int argc, char **argv) {
    char s[] = {'H', 'E', 'L','L', 'D', '\0'};
    char t[] = {'G', 'E', 'L','L', '\0'};
    squeeze(s, t);
    printf("S: %s\r\n", s);
    int val = any(s, t);
    if (val == -1)
        puts("Failure");
    else
        printf("val %d\r\n", val);
    return 0;
}
int any(char s[], char t[]) {
    int i, j, q;
    for (i = j = 0; s[i] != '\0'; i++)
        for(q = 0; t[q] != '\0'; q++)
            if(s[i] == t[q])
                return q;
    return -1;

}
void squeeze(char s[], char t[]) {
    int i, j, q, c;
    for (i = j = 0; s[i] != '\0'; i++)
        for(q = c = 0; t[q] != '\0'; q++)
            if(s[i] == t[q]) {
                s[j++] = t[q];
                break;
            }

    s[j] = '\0';
}

//assumes t and s are same size
void my_strcat(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i++] != '\0');
    while ((s[i++] = t[j++]) != '\0');// copy it
}
