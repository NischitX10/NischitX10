#include<stdio.h>
const max=100; 
typedef struct
{
    int data[max];
    int f;
    int r;
}DQueue;
int insert(DQueue *q,int v, int side)
{
    if((side==1 && q->r=max-1)||side==0&&q->f==0 && q->r==max-1)
    if(q->f==0 && q->r==max-1)
    { 
        printf("full");
        return 0;
    }
    if(q->r==-1)
    {
        q->f=q->r=0;
        q->data[q->r]=v;
        return 0;
    }
    if(side==1)
    if(q->r!=max-1)
    {
        q->r++;
        q->data[q->r]=v;
    }
    else
    {
        for(int i=q->f;i<q->r;i++)
        {
            q->data[i+1]=q->data[i];
            q->data[q->r]=v;
            q->f--;
        }
        if(side=0)
        {
            if(q->f!=0)
            {
                q->f--;
                q->data[q->f]=v;
            }
            else
            {
                for(int i=q->r;i>=q->f;i--)
                {
                    q->data[i+1]=q->data[i];
                    q->data[q->f]=v;
                    q->r++;
                }
                return 0;
            }
        }
        
    }
    
}
int del(DQueue *q,int *m,int side)
{
    if(q->f==-1)
    {
        printf("empty");
        return 0;
    }
    if(q->f==q->r)
    {
        *m=q->data[q->f];
        q->f=q->r==-1;
    }
    elseif(side==0)
    {
        *m=q->data[q->f];
        q->f++
    }else
    {
        *m=q->data[q->r];
        q->r--;
    }
    return 0;
}
int main()
{
    int side;
    int m;
    DQueue q1;
    q1.f=q1.r=-1;
    int p=insert(&q1,20,side); 
    del(&q1,&m,side);

}
