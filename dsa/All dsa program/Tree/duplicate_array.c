//Searching of duplicate inside an array
#include<stdio.h>
#define MAX 6
int duplicate(int yt[]);
int main()
{
    int arr[MAX]={89,78,67,89,78,90};
    int f=duplicate(arr);
    if(0)
    {
        printf("\nduplicate not found in an array\n");
    }
    else
    {
        printf("\nFinding dulicate complete\n");
    }
    
    return 0;
}
int duplicate(int yt[])
{
    int x=0;
    int a=0;
    for(int i=0;i<MAX-1;i++)
    {
        a=a+1;
        for(int j=a;j<MAX-1;j++)
        {
            if(yt[i]==yt[j])
            {
                printf("\n%d\n",yt[i]);
            }   
        }
    }
    return x;
}