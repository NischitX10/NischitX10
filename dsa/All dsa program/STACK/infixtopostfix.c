#include<stdio.h>
#define MAX 20
typedef struct{
    int data[MAX];
    int top;
}stack;
 stack s1;
 int push(stack *s,int v)
 {
     if(s->top==MAX-1)
     {
         printf("Overflow");
         return 1;
     }
     else
     {
         s->top++;
         s->data[s->top]=v;
         return 0;
     }
 }
 int pop(stack *s,int *v)
 {
     if(s->top==-1)
     {
         printf("underflow");
         return 1;
     }
     else
     {
         *v=s->data[s->top];
         s->top--;
         return 0;

     }
 }
 int is_operand(int x)
 {
     if((x>=65&& x<=90) || (x>=97 && x<=122) || (x>=48 && x<=57))
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }
 int get_v(char op)
 {
     int t;
     switch (op)
     {
     case '+':
     case'-':t=1;
         break;
     case'*':
     case'/':t=2;
     break;
     case '^':t=3;
     break;
     default:
     printf("not found sorry");
     }
     return t;
 }
 int is_l_to_h(char o1,char o2)
 {
     if(get_v(o1)<get_v(o2))
     return 1;
     else
         return 0;
 }
 //operation performed
  int infix_to_postfix(char *inp,char*out)
  {
      int m,k=0,n,i=0;
      while(inp[i]!='\0')
      {
          if(is_operand(inp[i]))
          {
              out[k++]=inp[i];
          }
          else if(inp[i]=='(')
          {
              push(&s1,inp[i]);
          }
          else if(inp[i]==')')
          {
              while(1)
              {
                  pop(&s1,&m);
              if(m=='(')
                  break;
              out[k++]=m;

          }
      }
else
    {
        if(s1.top==-1)
        {
            push(&s1,inp[i]);
        }
        else
        {
            pop(&s1,&n);
            if(n=='(')
            {
                push(&s1,n);
                push(&s1,inp[i]);
            }
            else if(is_l_to_h(n,inp[i]))
                {
                    push(&s1,n);
                    push(&s1,inp[i]);
                }
                else
                {
                    out[k++]=n;
                    continue;
                }
            }
    }
    i++;
    }   
            while(s1.top!=-1)
            {
                pop(&s1,&m);
                out[k++]=m;
            }
  }   
 int main()
 {
    char inp[100]; //"a/b-k*(d-e*f+g)/p";
    int l = 0;
    int i = 0;
    printf("Enter infix expression: ");
    gets(inp);
    while(inp[i]!='\0'){
        l++;
        i++;
    }
    char out[l+1];
    s1.top = -1;
    infix_to_postfix(inp, out);
    i = 0;
    while(out[i]!='\0'){
        printf("%c", out[i]);
        i++;
    }
    return 0;
 }