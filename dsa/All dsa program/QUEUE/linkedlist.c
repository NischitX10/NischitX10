//Queue using linked list 
//Author:Nischit
/*Algoritm
Step 1: Allocate the space for the new node PTR.
Step 2: SET PTR -> DATA = VAL.
Step 3: IF FRONT = NULL. SET FRONT = REAR = PTR. SET FRONT -> NEXT = REAR -> NEXT = NULL. ELSE. SET REAR -> NEXT = PTR. SET REAR = PTR. SET REAR -> NEXT = NULL. [END OF IF]
Step 4: END.
*/
#include<stdio.h>
#include<stdlib.h>
#define m 5
struct node
{
	int data;
	struct node *nxt;
};
typedef struct
{
	struct node *r,*f;
}queue;
int insert(queue *q,int n)
{
	struct node *ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("Full Queue.\n");
		return 1;
	}
	ptr->data=n;
	ptr->nxt=NULL;
	if(q->r==NULL)
	{
		q->r=q->f=ptr;
	}
	else
	{
		q->r->nxt=ptr;
		q->r=ptr;
	}
	return 0;
}
int delete(queue *q,int *n)
{
	if(q->f==NULL)
	{
		printf("Empty Queue.\n");
		return 1;
	}
	if(q->f==q->r)
	{
		*n=q->f->data;
		free(q->f);
		q->r=q->f=NULL;
	}
	else
	{
		struct node *ptr=q->f;
		*n=q->f->data;
		q->f=q->f->nxt;
		free(ptr);
	}
	return 0;
}
int main()
{
	queue q;
	q.r=q.f=NULL;
	int n,x,y;
	for(int i=0; i<m; i++)
	{
		x=insert(&q,rand()%34);
	}
	for(int i=0; i<m; i++)
	{
		y=delete(&q,&n);
		printf("%d ",n);
	}
	printf("\n");
	return 0;
}
