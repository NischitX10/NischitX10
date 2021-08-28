#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL,*Naya=NULL;

typedef struct
{
    struct node *top;
}stack;

void create(struct node *h)
{
    struct node *curr;
    for(int i=0;i<5;i++)
    {
        curr=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&curr->data);
        curr->next=NULL;
        if(head==NULL)
        {
            head=curr;
            h=curr;
        }
        else
        {
            h->next=curr;
            h=curr;
        }
    }
}
int push(stack *s2,struct node *p)
{
    struct node *curr;
    while(p!=NULL)
    {
    curr=(struct node*)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("overflow");
    }
    curr->data=p->data;
    curr->next=s2->top;
    s2->top=curr;
    p=p->next;
  }
}
int rlink(stack *s2,struct node *he)
{
    struct node *ptr=head;
    int i=0;
    struct node *p;
    p=s2->top;
    if(s2->top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        while(s2->top!=NULL)
        {
            if(i==0)
            {
                head->data=s2->top->data;
                s2->top=s2->top->next;
                free(p);
                i++;
            }
            else{
                p=s2->top;
                ptr=ptr->next;
                ptr->data=s2->top->data;
                 s2->top=s2->top->next;
                 free(p);
            }
        }
            
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
    stack s;
    s.top=NULL;
    struct node *ptr=head;
    create(head);
    push(&s,head);
    rlink(&s,head);
    display(head);
    return 0;
}