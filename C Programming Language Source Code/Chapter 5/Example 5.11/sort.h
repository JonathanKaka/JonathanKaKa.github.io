#ifndef __SORT_H
#define __SORT_H

//---�궨��---
#define MAXLINES 5000   //��������������
char *lineptr[MAXLINES];        //ָ���ı��е�ָ��

#define MAXLEN 1000
int getline(char *,int);
char *alloc(int);

#define ALLOCSIZE 10000

//---sort��غ�������---
int readlines(char *lineptr[],int nlines);
void writelines(char *lineptr[],int nlines);
void qsort(void *lineptr[],int left,int right,int(*comp)(void *,void *));
int numcmp(char *,char *);
void swap(void *v[],int i,int j);

#endif