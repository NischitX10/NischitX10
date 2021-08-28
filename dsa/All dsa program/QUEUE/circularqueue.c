#include<stdio.h>
const max=100;
typedef struct 
{
    int data[max];
    int f;
    int r;
}CQueue;
 int insert(CQueue *q,int v)
 {
     if(q->f==(q->r+1)%max)
     {
         printf("OF");
         return 1;
     }
     if(q->r==-1)
     {
     q->f=q->r=0;
     q->data[q->r]=v;
     }
 else
 {
     q->r=(q->r+1)%max;
     q->data[q->r]=v;
 }
 return 0;
 }
 int del(CQueue *q, int *m)
 {
    if(q->f==-1)
    {
        printf("NOT FOUND");
        return 1;
    } 
    if(q->f==q->r)
    {
     *m=q->data[q->f];
     q->f=q->r=-1;   
    }
    else
    {
        *m=q->data[q->f];
        q->f=(q->f+1)%max;
    }
    return 0;
 }
  
 
 
 int main()
 {
     int m;
     CQueue q1;
     q1.f=q1.r=-1;
     int p=insert(&q1,20);
     int o=del(&q1,&m);
    return 0;
 }
