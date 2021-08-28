#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
}*head=NULL;

//creatation of the node
void create(struct node *p)
{
    struct node *curr;
    int i;
    for(i=0;i<5;i++)
   {
       curr=(struct node*)malloc(sizeof(struct node));
       scanf("%d",&curr->data);
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
int count(struct node *s)
{
    int i;
    while(s!=NULL)
    {
        i++;
        s=s->next;
         }
         return i;
}
void insert(struct node *p,int pos,int no)
{
    struct node *curr;
    if(pos<0 && pos>count(p))
            return;
    curr=(struct node*)malloc(sizeof(struct node));
    curr->data=no;
    if(pos==0)
    {
        curr->next=head;
        head=curr;
    }
    else
    {
    
    for(int i=0;i<pos-1;i++)
    {
        p=p->next;
    }
    curr->next=p->next;
    p->next=curr;
}
}
//inserting always on the last node
void Linsert(struct node *p)
{
    struct node *curr;
    while(p)
    {
        p=p->next;
    }
    curr=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&curr->data);
    curr->next=NULL;
    p->next=curr;
    p=curr;
}

//inserting in the sorted linked list

void sinsert(struct node *p,int no)
{
    struct node *q,*curr;
    curr=(struct node*)malloc(sizeof(struct node));
    while(p->data<no)
    {
        q=p;
        p=p->next;
    }
    curr->next=p;
    q->next=curr;
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
} 
int main()
{
    int index,val;
    create(head);
    printf("enter the pos and value\n");
    scanf("%d%d",&index,&val);
    insert(head,index,val);
    display(head);
    return 0;
}
