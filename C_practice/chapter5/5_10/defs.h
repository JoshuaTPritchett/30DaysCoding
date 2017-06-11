#ifndef __DEFS_H__
#define __DEFS_H__

#define NUMBER '0'
/* Going to allow 1000 values deep */
#define MAXVALS 100
/* Going to allow 100 chars at a time */
#define MAXCHARS 100

void push(double c);
double *pop(void);

int getop(void);
int getch(void);
void ungetch(int c);



#endif
