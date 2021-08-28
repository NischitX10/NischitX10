#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prv;
}*head=NULL;

//create double linked list
void create(struct node *p)
{
    int i;
    struct node *curr;
    for(i=0;i<5;i++)
    {
        curr=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&curr->data);
        curr->next=NULL;
        curr->prv=NULL;
        if(head==NULL)
        {
            head=curr;
            p=curr;
        }
        else
        {
            p->next=curr;
            curr->prv=p;
            p=p->next;
        }
    }
}
//counting node
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
//display the double linked list
void display(struct node *p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
//inserting in double linked list
void insert(struct node *p,int index,int no)
{
    struct node *curr;
    if(index<0||index>count(p))
    {
        return ;
    }
curr=(struct node *)malloc(sizeof(struct node));
curr->data=no;
curr->next=NULL;
curr->prv=NULL;
if(index==0)
{
    curr->next=head;
    head->prv=curr;
    head=curr;
}
else
{
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
    }
    curr->next=p->next;
    curr->prv=p;
    p->next=curr;
    p->next->prv=curr;
}
}
//main function
int main()
{
    int pos,no1;
    create(head);
    printf("\nEnter the pos & no\n");
    scanf("%d%d",&pos,&no1);
    insert(head,pos,no1);
    display(head);
}
