#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

main(int argc,char *argv[])
{
    int nlines;     //读入的输入行数
    int numeric;    //若进行数值排序，则numeric的值为1

    if(argc>1&&strcmp(argv[1],"-n")==0)
        numeric=1;
    if((numeric=readlines(lineptr,MAXLINES))>=0)
    {
        //qsort((void **)lineptr,0,nlines-1,(int(*)(void *,void *))(numeric ? numcmp:strcmp));
        qsort((void **)lineptr,0,nlines-1,(numeric?(int(*)(void *,void *))numcmp:(int(*)(void *,void *))strcmp));
        
        writelines(lineptr,nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

int readlines(char *lineptr[],int maxline)
{
    int len,nlines;
    char *p,line[MAXLEN];
    nlines=0;
    while((len=getline(line,MAXLEN))>0)
    {
        if(nlines>=MAXLINES||(p=alloc(len))==NULL)
            return -1;
        else
            {
                line[len-1]='\0';   //删除换行符
                strcpy(p,line);
                lineptr[nlines++]=p;
            }
    }
}

void writelines(char *lineptr[],int nlines)
{
    int i;
    for(i=0;i<nlines;i++)
    {
        printf("%s\n",lineptr[i]);
    }
}

void swap(void *v[],int i,int j)
{
    void *temp;
    temp=v[i];
    v[i]=v[j];
    v[j]=temp;
}



void qsort(void *v[],int left,int right,int (*comp)(void *,void *))
{
    int i,last;
    swap(v,left,(left+right)/2);
    last=left;

    for(i=left+1;i<=right;i++)
    {
        if((*comp)(v[i],v[left])<0)
            swap(v,++last,i);
    }
    swap(v,left,last);
    qsort(v,left,last-1,comp);
    qsort(v,last+1,right,comp);
}

int numcmp(char *s1, char *s2)
{
    double v1,v2;

    v1=atof(s1);
    v2=atof(s2);
    if(v1<v2)
        return -1;
    else if(v1>v2)
        return 1;
    else
        return 0;
}


static char allocbuf[ALLOCSIZE];
static char *allocp=allocbuf;

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE-allocp>=n)
    {
        allocp+=n;
        return allocp-n;
    }
    else
    {
        return 0;
    }
}

int getline(char *s,int len)
{
    int c,i;
    for(i=0;i<len-1 && (c=getchar())!=EOF && c!='\n';++i)
    {
        s[i]=c;
    }
    if(c=='\n')
    {
        s[i]=c;
        ++i;
    }
    s[i]='\0';

    return i;
}