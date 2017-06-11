#include <stdio.h>
#include <stdlib.h>
#include "day.h"

int
main(int argc, char *argv[]) {
    int i = day_of_year(1990, 10, 8);
    printf("I value: %i\r\n", i);
    int *pmonth = malloc(sizeof(int));
    int *pday = malloc(sizeof(int));
    month_day1(1990, i, pmonth, pday);
    printf("pmonth value: %d, pday value: %d\r\n", *pmonth, *pday);
    month_day2(1990, i, pmonth, pday);
    printf("pmonth value: %d, pday value: %d\r\n", *pmonth, *pday);

    char *t = month_name(10);
    printf("month name:%s\r\n", t);
    t = month_name2(10);
    printf("month name:%s\r\n", t);


//    test();
    free(pmonth);
    free(pday);

    return 0;
}
