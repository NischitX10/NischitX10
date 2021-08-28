#include<stdio.h>
#include<stdlib.h>
struct node
{
int r;
int c;
int v;
struct node *next;
}*head=NULL,*first=NULL,*H3=NULL;

void create()
{
    struct node *curr,*ptr;
    head=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the row & column with value you want\n");
    scanf("%d%d%d",&head->r,&head->c,&head->v);
    head->next=NULL;
    ptr=head;
    for(int i=0;i<head->v;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the row & column with value\n");
        scanf("%d%d%d",&curr->r,&curr->c,&curr->v);
        curr->next=NULL;
        ptr->next=curr;
        ptr=curr;

    }
}
//creating the second matrix
void create2()
{
    struct node *curr,*ptr;
    first=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the row & column with value you want\n");
    scanf("%d%d%d",&first->r,&first->c,&first->v);
    first->next=NULL;
    ptr=first;
    for(int i=0;i<first->v;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        printf("\nEnter the row & column with value\n");
        scanf("%d%d%d",&curr->r,&curr->c,&curr->v);
        curr->next=NULL;
        ptr->next=curr;
        ptr=curr;

    }
}
//adding of two sparse matrix
void simplify(struct node *p,struct node *q)
{
struct node *r;
H3=p;
while(p!=NULL)
{
p=p->next;
}
p->next=q;
//searching for the similar row and column(adding)
p=H3;
while(p!=NULL)
{
    q=p->next;
    r=p;
while(q!=NULL)
{
    if(p->r==q->r && p->c==q->c)
    {
        p->v=p->v+q->v;
        r->next=q->next;
          free(q);
                q=r;
    }
r=q;
q=q->next;
}
}
}
/*void mul(struct node *p,struct node *q)
{
struct node *curr;
curr=(struct node*)malloc(sizeof(struct node));
for(;p!=NULL;p=p->next)
{
    for(;q!=NULL;q=q->next)
    {
        if(H3==NULL)
        {
            H3=curr;
            H3->r=p->r+q->r;
            H3->c=p->c+q->c;
            H3->v=p->v+q->v;
            r=curr;
        }
        else
        {
            r->v=p->v+q->v;
            r
        }
        
    }
}
}
*/
void display(struct node *p)
{
    for(int i=0;i<head->r;i++)
    {
        for(int j=0;j<head->c;j++)
    {
        if(j==p->c)
    {
        printf("%d ",p->v);
        p=p->next;
    }
        else
        {
            printf("0 ");
        }   
    }
}
}
int main()
{
    create();
    create2();
    mul(head,first);
    simplify(head->next,first->next);
    display(H3->next);
    return 0;
}
