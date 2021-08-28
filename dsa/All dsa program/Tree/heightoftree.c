#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *lptr;
	struct node *rptr;
};
void create(struct node **root,int data);
void *display(struct node *NODE);
int  height(struct node *root);
int main()
{
	int ch ,dat;
	struct node *root=NULL;
	struct node *NODE=NULL;
	while (1)
	{
		printf("1.create\n");
		printf("2.display\n");
		printf("3.exit\n");
		printf("4.height of the tree\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("enter the data \n");
				scanf("%d",&dat);
				create(&root,dat);
				break;
			case 2:
				NODE=root;
				display(NODE);
				printf("\n");
				break;
			case 3:
				exit(1);
			case 4:
				printf("the height of the tree is %d\n",height(root));
				break;
			default:
				printf("wrong choice\n");
		}
	}
	return 0;
}
void create(struct node **root,int data)
{
	struct node *newnode,*parent,*ptr;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=data;
	newnode->lptr=NULL;
	newnode->rptr=NULL;
	if (*root==NULL)
	{
		*root=newnode;
	}
	else 
	{
		ptr=*root;
		parent=*root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if (data<ptr->data)
			{
				ptr=ptr->lptr;
			}
			else  
			{
				ptr=ptr->rptr;
			}
		}
	if (data<parent->data)
	{
		parent->lptr=newnode;
	}
	else
	{
		parent->rptr=newnode;
	}
  }
}
void *display(struct node *NODE)
{
//	preorder print 
	if (NODE!=NULL)
	{
		printf("\n%d",NODE->data);
        display(NODE->lptr);
		display(NODE->rptr);
	}
}
int height(struct node *root)
{
	if (root==NULL)  
       return 0; 
   else 
   { 
       int left = height(root->lptr); 
       int right = height(root->rptr); 
       if (left > right)  
           return(left+1); 
       else return(right+1); 
   } 
}