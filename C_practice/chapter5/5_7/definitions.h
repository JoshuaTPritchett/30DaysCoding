/*
 * Definitions file for K&R chapter 5.6
 * @author Joshua T. Pritchett
 */
#ifndef __DEFINITIONS_H__
#define __DEFINITIONS_H__
/* Visible in readlines.c */
int get_input(void);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int getline1(char *line, int size);

/* Visible in qsort.c */
void qsort1(char *lineptr[], int left, int right);
void swap(char *lineptr[], int pos1, int pos2);

/* Visible in alloc.c */
char *alloc(int n);
void afree(char *p);
#endif
