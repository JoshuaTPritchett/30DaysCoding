#ifndef __CALC_H__
#define __CALC_H__

#define NUMBER '0'

/* Stack functions that we will be using */
void push(double f);
double pop(void);
void  peek(void);
void clear_stack(void);
int get_stack_size(void);
void swap_two(void);
int print_elements(void);


int getop(char s[]);
int getch(void);
void ungetch(int);
int my_getline(char s[], int size);
int getop_2(char s[], int size);


#endif
