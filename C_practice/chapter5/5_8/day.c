#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "day.h"

/* char can be used to illustrate trivial integer values */
static char daytab[2][13]/* [row][col] */ = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
/*
static char *daytab2[2] =  {
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};*/
static int *ll;

void test() {
    ll = malloc(sizeof(int) * 1);
    *ll = 3;
    /*create an array of ints */
    unsigned int *c[13] = {NULL};
    size_t i, q;
    for (i = 0; i < 13; i++) {
        *(c + i) = malloc(sizeof(int) * 13); /* Allocate the 13 pointers */
    }
    int *lq = malloc(sizeof(int) * 13);
    for (i = 0; i < 13; i++)
        *(lq + i) = i;
    for (i = 0; i < 13; i++)
        printf("intger value in lq %d\n", lq[i]);
    for (q = 0; q < 13; q++)
        for(i = 0; i < 13; i++)
            c[q][i] = i;
    for (q = 0; q < 13; q++)
        for(i = 0; i < 13; i++)
            printf("c value %d\n", *(*(c+q) + i));

    for (q = 0; q < 13; q++)
           free(*(c + q));
    free(lq);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day1(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0 || year%400 == 0);
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
void month_day2(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    leap = (year%4 == 0 && year%100 != 0 || year%400 == 0);
    char *dt = *(daytab + leap);
    for (i = 1; yearday > *(dt + i); i++)
        yearday -= *(dt + i);
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n) {
    static char *name[] = {
            "Illegal month",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];

}
char *month_name2(int n) {
    static char *name[] = {
            "Illegal month",
            "January", "February", "March",
            "April", "May", "June",
            "July", "August", "September",
            "October", "November", "December"
    };

    return (n < 1 || n > 12) ? name[0] : name[n];

}
