#ifndef __SORT_H
#define __SORT_H

//---宏定义---
#define MAXLINES 5000   //待排序的最大行数
char *lineptr[MAXLINES];        //指向文本行的指针

#define MAXLEN 1000
int getline(char *,int);
char *alloc(int);

#define ALLOCSIZE 10000

//---sort相关函数声明---
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(void *lineptr[],int left,int right,int(*comp)(void *,void *));
int numcmp(char *,char *);
void swap(void *v[],int i,int j);

#endif