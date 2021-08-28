#include<stdio.h>
#include<stdlib.h>
struct node
{
int no;
int exp;
struct node *next;
}*head=NULL,*head1=NULL,*head3=NULL;

void create(struct node *p)
{
    struct node *curr;
    printf("\nEnter the first polynomial\n");
    for(int i=0;i<3;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d",&curr->no,&curr->exp);
        curr->next=NULL;
        if(head==NULL)
        {
            head=curr;
            p=curr;
        }
        else
        {
            p->next=curr;
            p=p->next;
        }
    }
}
//creating the second ploy
void create2(struct node *p)
{
    struct node *curr;
    printf("\n........................\n");
    printf("enter the second polynomial\n ");
    for(int i=0;i<3;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        scanf("%d%d",&curr->no,&curr->exp);
        curr->next=NULL;
        if(head1==NULL)
        {
            head1=curr;
            p=curr;
        }
        else
        {
            p->next=curr;
            p=p->next;
        }
    }
}
//multiplication of two poly
void mul(struct node *p,struct node *q)
{
struct node *curr,*r;
curr=(struct node*)malloc(sizeof(struct node));
curr->next=NULL;
for(;p!=NULL;p=p->next)
{
    for(;q!=NULL;q=q->next)
    {
        if(head3==NULL)
        {
            head3=curr;
            r=curr;
            curr->no=p->no+q->no;
            curr->exp=p->exp+q->exp;
        }
        else
        {
            r->no=p->no+q->no;
            r->exp=p->exp+q->exp;
            r=r->next;
        }
        
    }
}
}

//adding of two poly
void simplify(struct node *t)
{
struct node *r,*p,*q;
p=head1;
t=head1;
while(p!=NULL)
{
p=p->next;
}
p->next=head1;
//searching for the similar row and column(adding)
p=t;
while(p!=NULL)
{
    q=p->next;
    r=p;
while(q!=NULL)
{
    if(p->exp==q->exp)
    {
        p->no=p->no+q->no;
        r->next=q->next;
          free(q);
                q=r->next;
    }
    else
    {
      r=q;
       q=q->next;   
    }
}
p=p->next;
}
}

void display(struct node *p)
{
    printf("\n the polynomial is\n");
    while(p!=NULL)
    {
        printf("%d%d",p->no,p->exp);
        p=p->next;
    }
}
int main()
{
    create(head);
    create2(head1);
    mul(head,head1);
    simplify(head3);
    display(head3);
    return 0;
}
