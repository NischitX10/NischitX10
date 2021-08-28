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
void delete(struct node *p,int pos)
{
    struct node *q=NULL;
    if(pos<0 && pos>count(p))
            return;
    if(pos==0)
    {
        head=head->next;
        free(p);
        p=head;
    }
    else
    {
        for( int i=0;i<pos-1;i++)
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
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
} 
int main()
{
    int index;
    create(head);
    printf("enter the pos\n");
    scanf("%d",&index);
    delete(head,index);
    display(head);
    return 0;
}
