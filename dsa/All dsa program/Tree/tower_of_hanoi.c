//Tower of hanoi
#include<stdio.h>
void TOH(int n,int a,int b,int c);
int main()
{
    int n;
    int a=1,b=2,c=3; 
    printf("\nEnter the no of disk\n");
    scanf("%d",&n);
    TOH(n,a,b,c);
    return 1;
}
void TOH(int n,int a,int b,int c)
{
    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("(%d,%d)\n",a,c);
        TOH(n-1,b,a,c);
    }
}