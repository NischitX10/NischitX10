#include<stdio.h>
#include<stdlib.h>
struct node{
    char data;
    struct node *next;
};
typedef struct{
    struct node *top;
}stack;

void push(stack *s1,char x)
{
    struct node *curr;
    curr=(struct node*)malloc(sizeof(struct node));
    if(curr==NULL)
    {
        printf("Overflow");
    }
    else
    {
        curr->data=x;
        curr->next=s1->top;
        s1->top=curr;
    }
}
void pop(stack *s1,struct node **v)
{
    struct node *ptr;
    if(s1->top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        ptr=s1->top;
        s1->top=s1->top->next;
        *v=ptr;
        free(ptr);
    }
}
int isbalanced(char *exp)
{
    int i;
    stack s;
    s.top=NULL;
    struct node *m;
    for(i=0;exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
        push(&s,exp[i]);
        }
        else if(exp[i]==')')
        {
            if(s.top==NULL)
            {
                return 1; 
            }  
            else
            {
               pop(&s,&m);
            }
    }
    }
        if(s.top==NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
}
int main()
{
    char *exp="(((a+b)+(d+e))";
    printf("%d",isbalanced(exp));
    return 0;
}
