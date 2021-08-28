//Program Name:- Sum of two Matrices.
#include<stdio.h>
 void main()
 {
 int a[10][10],b[10][10],c[10][10],i,j,row,col;
 
 printf("\n Enter the row and column size : ");
 scanf("%d %d",&row,&col);
 
 printf("\n Enter the matrix 1 :\n\n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 scanf("%d",&a[i][j]);
 }
 }
 
 printf("\n Enter the matrix 2 :\n\n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 scanf("%d",&b[i][j]);
 }
 }
 
 for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 c[i][j]=a[i][j]+b[i][j];
 }
 }
 
 printf("\n The sum is : \n");
 for(i=0;i<row;i++)
 {
 for(j=0;j<col;j++)
 {
 printf(" %d ",c[i][j]);
 }
 printf("\n");
 }
 }