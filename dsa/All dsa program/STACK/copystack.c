#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
typedef struct{
    struct node *top;
}stack;

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
void copy(stack *s1,stack *s2)
{
    struct node *curr,*p;
    while(s1->top!=NULL)
    {
        curr=(struct node*)malloc(sizeof(struct node*));
        curr->data=s1->top->data;
        curr->next=NULL;
        if(s2->top==NULL)
        {
            s2->top=curr;
            p=curr;
        }
        else
        {
            p->next=curr;
            p=p->next;
        }
        
    }
}
void display(stack *s2)
{
    struct node *p;
    p=s2->top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    stack s;
    stack st2;
    s.top=NULL;
    st2.top=NULL;
    push(&s,15);
    push(&s,67);
    push(&s,90);
    push(&s,7);
    push(&s,9);
    copy(&s,&st2);
    display(&st2);
    return 0;

}