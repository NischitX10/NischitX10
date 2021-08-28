#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prv
}*head=NULL;

void create(struct node*p)
{
    struct node *curr;
    for(int i=0;i<5;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&curr->data);
        curr->next=head;
        curr->prv=head;
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
            head->prv=curr;
        }
    }
}

//inserting in double circular
void insert(struct node *p,int index,int no)
{
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    curr->data=no;
    curr->next=NULL;
    curr->prv=NULL;
    if(index==0)
    {
        curr->prv=head->prv;
        curr->next=head;
        head->prv=curr;
        head=curr;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        curr->next=p->next;
        curr->prv=p;
        p->next=curr;
        p->next->prv=curr;
        
    }
}
//deletion in double circular
void delete(struct node *p,int index)
{
    struct node *p;
    struct node *q;
    if(index==0)
    {
        head=head->next;
        head->prv=p->prv;
        free(p);
        p=head;
    }
else
{
    for (int i = 0; i <index-1; i++)
    {
    q=p;
    p=p->next;
    }
    q->next=p->next;
    p->next->prv=q;
    free(p);
    p=q->next;
}
}
int main()
{
    int pos,no;
    create(head);
    count(head);
    printf("\nenter the pos & no you want to insert");
    scanf("%d%d",&pos,&no);
    insert(head,pos,no);
    delete(head,2);
    display(head);
    return 0;
}

