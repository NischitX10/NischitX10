#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head=NULL;


//creatation of node
void create(struct node *p)
{
	int i;
	struct node *curr;
	for(i=0;i<10;i++)
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


 //display
 void display()
 {
 	struct node *p=head;
 	printf("\n------------------------------------------------------------------------\n");
 	while(p!=NULL)
 	{
 		printf("%d ",p->data);
 		p=p->next;
	 } 	
 }	
 
 
//recurcive display 
 void rdisplay(struct node *p)
	 {
	 	if(head==NULL)
	 	{
	 		printf("\nNo node\n");
		 }
		 if(p!=NULL)
		 {
		 	printf("%d  ",p->data);
		 	return rdisplay(p->next);
		 }
	 }
	 
	 
//count the number of node
 int count(struct node *p)
 {
    int c=0;
 	if(p==NULL)
 	{
 		return 0;
	 }
while(p!=NULL)
{
	c++;
	p=p->next;
}
return c;
}
 
 //recursive count
 int rcount(struct node *p)
 {
    int c=0;
 	if(p==NULL)
 	{
 		return 0;
	 }
	 if(p)
	 {
	 	return rcount(p->next)+1;
	 } 
}
 //interation addition
 int sum(struct node *p)
 {
    int c=0;
 	if(p==NULL)
 	{
 		return 0;
	 }
while(p!=NULL)
{
	c+=p->data;
	p=p->next;
}
return c;
}
 //recursive addition
 int rsum(struct node *p)
 {
    int c=0;
 	if(p==NULL)
 	{
 		return 0;
	 }
	 if(p)
	 {
	 	return sum(p->next)+p->data;
	 } 
}

//MAX element in the linked list
 int max(struct node *p)
 {
 	int m=0;
 	while(p)
 	{
 		if(p->data>m)
 		{
 			m=p->data;
		}
		p=p->next;
	}
	return m;
}

//MAX using recursive in linked list
int rmax(struct node *p)
{
	int x=0;
		if(p==0)
           return 0;
         x=rmax(p->next);
           return x>p->data ?x:p->data;
}



//searching in the linked list
int search(struct node *p,int number)
{
	while(p)
	{
	if(p->data==number)
	{
		return p->data;
	}
	p=p->next;
        }
		return 0;
}

int rsearch(struct node *p,int number)
{
	int x=0;
	if(p==NULL)
	{
		return 0;
	}
	x=rsearch(p->next,number);
	if(x==number)
	{
		return x;
	}
	else
	{
		return NULL;
	}
}

int Fsearch(struct node *p,int number)
{
	struct node *q;
		for(p=head; p!=NULL;p=p->next)
		{
		if(p->data==number)
		{
		q->next=p->next;
		p->next=head;
		head=p;
		return p->data;
     }  
     q=p;
 }
     return NULL;
}

//INSERTION USING INDEX
void insert(struct node *p,int index,int no)
{
	struct node *curr;
	int i;
	curr=(struct node *)malloc(sizeof(struct node));
	curr->data=no;
	curr->next=NULL;
	if(index==NULL)
	{
		curr->next=head;
		head=curr;
	}
	else
	{
		for(i=1;i<index-1;i++)
		{
			p=p->next;
		}
		curr->next=p->next;
		p->next=curr;
	}
	
}
//INSERTION AT LAST NODE
void Linsert(struct node *p,int no)
{
	struct node *curr;
	int i,t;
	t=count(p);
	curr=(struct node *)malloc(sizeof(struct node));
	curr->data=no;
	curr->next=NULL;
		if(p==NULL)
		{
			head=curr;
			p=curr;
		}
		else
		{
		for(i=1;i<t;i++)
		{
			p=p->next;
		}
		p->next=curr;
		p=p->next;
	}
}

//Sorting a link list in single link list
void sorting(struct node *p)
{
	struct node *q,*r,*s;
	while(p==head)
	{
	q=p->next;
	r=p;
	//moving q;
	while(q!=NULL)
	{
		if(q->data<p->data)
		{
			r->next=q->next;
			q->next=p;
			head=q;
			p=q;
			r=q;
			q=p->next;
	}	
	     r=q;
		q=q->next;
	}
	s=p;
	p=p->next;
}
	
	while(p!=head && p!=NULL)
	{
	//moving q for  comparing
	q=p->next;
	r=p;
		while(q!=NULL)
		{
			if(q->data<p->data)
			{
				r->next=q->next;
				q->next=p;
				s->next=q;
				p=q;
				r=q;
				q=p->next;
			}
			r=q;
			q=q->next;
		}
		s=p;
		p=p->next;
	}
}

int main()
	{
	create(head);
		//rdisplay(head);
		//printf("\n%d\n",sum(head));
		//printf("\n%d\n",rmax(head));
		//Fsearch(head,15);
		//Linsert(head,10);
		sorting(head);
		display();	
		return 0;
	}

