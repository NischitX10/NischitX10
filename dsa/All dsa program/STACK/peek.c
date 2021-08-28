#include<stdio.h>
#include<stdlib.h>
#define max 5
typedef struct{
    int data[max];
    int top;
}stack;
void push(stack *s1,int no)
{
    if(s1->top==max-1)
    {
        printf("Overflow");
    }
    else
    {
        s1->top++;
        s1->data[s1->top]=no;
    }
}
int peek(stack s,int pos)
{
    int x=-1;
    if(pos>s.top||pos<0)
    {
        printf("The positon your searching for doesn't exist");
        return 0;
    }
    else
    {
        x=s.data[s.top-pos-1];
    }
    return x;
}
int main()
{
stack s1;
int t;
s1.top=-1;
push(&s1,15);
push(&s1,21);
push(&s1,67);
push(&s1,90);
push(&s1,89);
printf("enter the postion you want to peek");
scanf("%d",&t);
int y=peek(s1,t);
printf("\n%d",y);
return 0;
}