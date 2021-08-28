//Removal of duplicate in linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;

void create(struct node *p,int a[])
{
    struct node *curr,*ptr;
    for(int i=0;i<7;i++)
    {
        curr=(struct node *)malloc(sizeof(struct node *));
        curr->data=a[i];
        curr->next=NULL;
        if(head==NULL)
        {
            head=curr;
            ptr=curr;
        }
        else
        {
            ptr->next=curr;
            ptr=curr;
        }
        
    }
}
void duplicate(struct node *p)
{
    struct node *q;
    struct node *r=p;
    while(p!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
        if(p->data==q->data)
        {
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
void display(struct node *q)
{
    while(q!=NULL)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}
int main()
{
    int arr[7]={6,8,4,6,2,8,9};
    create(head,arr);
    duplicate(head);
    display(head);
    return 0;
}