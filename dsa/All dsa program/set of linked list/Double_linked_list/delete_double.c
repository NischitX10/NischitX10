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
//delete in double linked list
void delete(struct node *p,int index)
{
    
    struct node *q;
    if(index<0||index>count(p))
    {
        return ;
    }
    if(index==0)
    {
        head=head->next;
        free(p);
        head->prv=NULL;
        p=head;
    }
    else
    {
        for(int i=0;i<index;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
        p=q->next;
        p->prv=q;
    }
}
//main function
int main()
{
    int pos,no1;
    create(head);
    printf("\nEnter the pos\n");
    scanf("%d",&pos);
    delete(head,pos);
    display(head);
}
