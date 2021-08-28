//Removal of duplicate in array sorted or unsorted works for both case
#include<stdio.h>
#define MAX 6
int duplicate(int yt[]);
void display(int cool[]);
int main()
{
    int ty=0,u=0;
    int arr[MAX]={9,2,7,4,7};
    int f=duplicate(arr);
    u=ty;
    if(f==0)
    {
        printf("\nDuplicate not found in an array deletion failed\n");
    }
    else
    {
        printf("\nFinding and removing duplicate complete\n");
    }
    display(arr);
    return 0;
}
int duplicate(int yt[])
{
    int a=0;
    int k,z=0;
    for(int i=0;i<=MAX-1;i++)
    {
        a=a+1;
        for(int j=a;j<=MAX-1;j++)
        {
            if(yt[i]==yt[j])
            {
                for(k=j;k<=MAX-1;k++)
                {
                    yt[k]=yt[k+1];
                }
                z=z+1;//counter
            }   
        }
    }
    if(z==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
}
void display(int cool[])
{
    for(int i=0;i<=MAX-1;i++)
    {
        printf("%d ",cool[i]);
    }

}