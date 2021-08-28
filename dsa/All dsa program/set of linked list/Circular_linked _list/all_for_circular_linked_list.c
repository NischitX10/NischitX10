#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void create(struct node *p)
{
    int i;
    struct node *curr;
    for(i=0;i<5;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&curr->data);
        curr->next=head;
        if(head==NULL)
        {
            p=curr;
            head=curr;
        }
        else
        {
            p->next=curr;
            p=curr;
        }
    }
}
 int count(struct node *p)
 {
    int c=0;
 	if(p==NULL)
 	{
 		return 0;
	 }
do
{
    c++;
    p=p->next;
} while (p!=head);
return c;
}

void insert(struct node *p,int index,int no)
{
    struct node *curr;
    curr=(struct node *)malloc(sizeof(struct node));
    curr->data=no;
    curr->next=NULL;
    if(index==0)
    {
        do
        {
            p=p->next;
        } while (p->next!=head);
        curr->next=head;
        head=curr;
        p->next=curr;
    }
    else
    {
        for (int i = 0; i < index-1; i++)
        {
            p=p->next;
        }
        curr->next=p->next;
        p->next=curr;
    }
}
//deletion of the circular link
void delete(struct node *p,int index)
{
    struct node *q;
    if(index<0||index>count(p))
    {
        return;
    }
    if(index==0)
    {
        do
        {
            p=p->next;
        } while (p->next!=head);
        p->next=head->next;
        free(head);
        head=p->next;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        free(p);
        p=q->next;
    }
}

void display(struct node *p)
{
    printf("\n...................\n");
 do
 {
     printf("%d ",p->data);
     p=p->next;
 } while (p!=head);
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
}