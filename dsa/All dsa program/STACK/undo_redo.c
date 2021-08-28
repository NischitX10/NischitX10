#include<stdio.h>
#include<stdlib.h>
enum op{redo,undo};
struct node{
    int data;
    struct node *next;
}*head=NULL;
typedef struct{
    struct node *top;
}stack;
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

void push(stack *s1,int x)
{
    struct node *curr;
    curr=(struct node*)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("overflow");
    }
    else
    {
        curr->data=x;
        curr->next=s1->top;
        s1->top=curr;
    }
}
int pop(stack *s2,struct node **v)
{
    if(s2->top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        *v=s2->top;
        s2->top=s2->top->next;
    }
    return 0;
}

int undo(stack *s1,struct node *s)
{
    struct node *pass;
    while(s1->top!=NULL)
        {
            s=s->next;
        }
        push(&s1,s->data);
        free(s);
}
int redo(stack *s1,struct node *s)
{
    struct node *m;
    while(s!=NULL)s
    {
        s=s->next;
    }
    pop(&s1,&m);
    s->next=m->next;
}
int main()
{
    stack s1;
    s1.top=NULL;
    char *s;
    enum op access;
    create(head);
    switch (access)
    {
    case 0:
        redo(&s,head);
        break;
    case 1:
    undo(&s,head);
    default:
        printf("you choose wrong option");
    }
    return 0;
}
