#include<stdio.h>
const MAX=100;
typedef struct
{
	int data[MAX];
	int front;
	int rear;
}Queue;
//insert
int insert(Queue *q,int v)
{
	if(q->rear==MAX-1)
	{
		printf("qfull");
		return 1;
	}
if(q->rear==-1)
{
	q->front=q->rear=0;
	q->data[q->rear]=v;
}
else
{
q->rear++;
q->data[q->rear]=v;
}
return 0;
}
//delete
int del(Queue *q,int *m)
{
	if(q->front==-1)
	{
		printf("QEMP");
		return 1;
	}
	if(q->front=q->rear)
	{
		*m=q->data[q->front];
		q->front=q->rear=-1;
	}
	else
	{
		*m=q->data[q->front];
		q->front++;
	}
	return 0; 
}
//delete for 2nd
int del2(Queue *q,int *m)
{
	if(q->front==-1)
	{
		printf("QEMP");
		return 1;
	}
	if(q->front=q->rear)
	{
		*m=q->data[q->front];
		q->front=q->rear=-1;
	}
	else
	{
		*m=q->data[q->front];
		for(int i=1;i<=q->rear;i++)
		{
			q->data[i-1]=q->data[i];
		}
	return 0; 
}
}

int main()
{
	Queue q1;
    int m;
	q1.front=q1.rear=-1;
	int p=insert(&q1,12);
	int q=del(&q,&m);
    return 0;
}