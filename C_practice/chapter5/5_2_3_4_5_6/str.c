#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include "mystdlib.h"

unsigned int my_strlen(char *s);
unsigned int new_strlen(char *s);
ptrdiff_t strlen3(char *s);
size_t strlen4(char *s); /* how actual strlen works */

void test_strcpy(void);

/*Various versions of strcpy */
void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);
void strcpy4(char *s, char *t);
char *strcpy5(char *dest, char *src);





/* strcmp */
int strcmp1(char *s, char *t);
int strcmp2(char *s, char *t);

/* My own implementation of strcat using pointers */
char *strcat1(char *s, char *t);


int strend(char *s, char *t);
char *strncpy1(char *s, char *t, int n);
char *strncat1(char *s, char *t, int n);
int
main(int argc, char **argv) {

    char *q = alloc(sizeof(char) * 1000);
    char *s = "Hello world";
    char *a = malloc(sizeof(char));/* One character */
    char *b = malloc(sizeof(char) * 10); /* a[10] or 10 characters */
    char *c = NULL;
    unsigned int str_len = my_strlen(s);
    printf("The length of the string %u\n", str_len);
    printf("The length of the string %u\n", new_strlen(s));

    char *t1 = "Hello World";
    char *t2 = malloc(sizeof(t1));
    printf("address of t2 %p\n", t2);
    char *t3;
    strcpy5(t2, t1);
    printf("address of t2 %p\n", t2);
    t3 = strcpy5(malloc(sizeof(t1)), t2);
    printf("t2 value: %s\n", t2);
    printf("t3 value: %s\n", t3);

    if (strcmp1("Hello World", "Hello World") == 0)
        printf("They are the same \n");
    if (strcmp1("Hello World", "Goodbye World") > 1);
        printf("Hello World is lexographically larger\n");
    if (strcmp1("Hello World", "Goodbye World") < 1 )
        printf("Hello World is lexographically smaller\n");

    if (strcmp2("Hello World", "Hello World") == 0)
        printf("They are the same \n");
    if (strcmp2("Hello World", "Goodbye World") > 1);
        printf("strcmp2 Hello World is lexographically larger\n");
    if (strcmp2("Hello World", "Goodbye World") < 1 )
        printf("strcmp2 Hello World is lexographically smaller\n");

    char *z = (char *) malloc(sizeof(char) * 26);
    strcpy(z, "Hello World, ");
    printf("String z %s\n", z);
    strcat1(z, "Tata for now!");
    printf("String z %s\n", z);
    assert(strcmp(z, "Hello World, Tata for now!") == 0);

    int ll = strend("hello baaab", "baaab");
    if (ll == 1)
        puts("It exists at the end");
    char *mm = malloc(sizeof(char) * 20);
    char *t = "aaaaa";
    puts("WE HERE");
    strncpy1(mm, t, 10);
    puts("done copying mm");
    printf("mm value %s\r\n", mm);

    char *qq = malloc(sizeof(char) * 40);
    strcpy(qq, "Hello world, ");
    printf("strcpy1 qq value %s\r\n", qq);
    strncat1(qq, "Goodbye world!", 4);
    printf("strcat1 qq value %s\r\n", qq);

    char *test = "hello world";
    /* When you move a pointer and dereference it, it goes based on the offset */
    test += 4;
    printf("test value %c\n", test[0]);

    if (strcmp("a", "b") < 0)
        puts("A is less than B");
    return 0;
}


/* DEFINED IN STRING.H */
unsigned int my_strlen(char *s) {
    unsigned int i;
    for (i = 0; *s != '\0'; s++, i++);
    return i;
}

unsigned int new_strlen(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;
    /* not +1 here because we do not want to know the number of elements strlen() +1 for null terminator*/
    return p - s;
}

/* Signed value return difference between pointers */
ptrdiff_t strlen3(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;
    /* not +1 here because we do not want to know the number of elements strlen() +1 for null terminator*/
    return p - s;


}
/* Unsigned value that will return the difference between pointers */
size_t strlen4(char *s) {
    char *p = s;

    while (*p != '\0')
        p++;

    return p - s;

}


void strcpy1(char *s, char *t) {
    int i;
    i = 0;
    while ((s[i] = t[i] != '\0'))
        i++;

}

void strcpy2(char *s, char *t) {
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

void strcpy3(char *dest, char *src) {
    while((*dest++ = *src++) != '\0')
        ;
}


void strcpy4(char *dest, char *src) {
    while ((*dest++ = *src++));
    /* Automatically checks for the null poiner */
    /* here * has higher precedence than ++ */


}

/* Actual strcpy implementation */
char *strcpy5(char *dest, char *src) {
    /* WHAT THE FUCKING FUCK */
    char *intial = &dest[0];
    while((*dest++ = *src++))
        ;
    /* WHY THE FUCK DOES &dest[0] not work?!?!?!
     * NOW I understand... I am an idiot --J T P*/
    return intial;
}

/*
 * strcmp: compares two strings that will return based
 * on lexograpic ordering
 * 1) negative -- if less than
 * 2) zero -- equal to
 * 3) greater than -- greater
 *
 * This is not quite like the real strcmp function
 */
int strcmp1(char *s, char *t) {
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

/* pointer variation of the above function */
int strcmp2(char *s, char *t) {
    for ( ; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;

    return *s - *t;
}

char *strcat1(char *s, char *t) {
    char *initial = &s[0];
    /* Plus 1 for null terminator */
    for ( ; *s != '\0'; s++)
        ;
    for ( ; *t != '\0'; t++, s++)
        *s = *t;
    *s = '\0';
    return initial;
}


int strend(char *s, char *t) {
    unsigned int i, q, z;
    /* One of the strings are empty we cannot compare them */
    if ((i = (strlen(s) - 1)) <= 0 || (q = (strlen(t) - 1)) <= 0)
        return 0;
    s += i; /* move the string to be compared to the end of the array */
    t += q;
    for (; *t; t--, s--)
        if (*t != *s)
            return 0;

    return 1;
}

char *strncpy1(char *dest, char *src, int n) {
    unsigned int i;
    char *initial =  &dest[0];
    for(i = 0; (*dest++ = *src++)  && i < n; i++)
        ;
    *dest = '\0';

    return initial;
}

char *strncat1(char *dest, char *src, int n) {
    char *initial = &dest[0];
    unsigned int i, des_len = strlen(dest);
    /* When you move a pointer you are in theory increasing or decreasing it's size */
    /* Damn this shit is hacky but works, I did it for learning purposes to say I could */
    for (i = strlen(dest), dest += i; (*dest++ = *src++) && (i < (des_len + n)); i++);
    *dest = '\0';
    return initial;

}

int strncmp1(char *dest, char *src, size_t n) {
    size_t i;
    for (i = 0; i < n && (*src == *dest); i++)
        if (*dest == '\0')
            return 0;

    return *dest - *src;

}
