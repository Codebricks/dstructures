#include<stdio.h>
#include<conio.h>
struct node
{
int info;
struct node *link;
};
struct node *start,*newptr;
struct node *create_new_node(int i);
void insertend(struct node *n);
void insertmid(struct node *o);
void insertbeg(struct node *m);
void reverse(int c);
void del(int d);
void display(struct node *x);
int count(struct node *c);
void main()
{
int info,a,c;
struct node *np;
char ch;
start=NULL;
clrscr();
do
{
printf("ENTER YOUR CHOICE:\n");
printf("Enter 1 to insert at begining\n");
printf("Enter 2 to insert after a given element\n");
printf("Enter 3 to insert at end\n");
printf("Enter 4 to delete a particular element\n");
printf("Enter 5 to reverse the current linked list\n");
scanf("%d",&a);
if(a==1)
{
printf("Enter the element\n");
scanf("%d",&info);
np=create_new_node(info);
insertbeg(np);
}
else if(a==2)
{
printf("Enter the element\n");
scanf("%d",&info);
np=create_new_node(info);
insertmid(np);
}
else if(a==3)
{
printf("Enter the element\n");
scanf("%d",&info);
np=create_new_node(info);
insertend(np);
}
else if(a==4)
{
printf("Enter the element\n");
scanf("%d",&info);
np=create_new_node(info);
del(info);
}
else if(a==5)
{
reverse(c);
}
display(start);
c=count(start);
printf("The number of nodes are %d\n",c);
printf("\nDo you want to proceed? y/n\n");
scanf(" %c",&ch);
}
while(ch=='y');
getch();
}
/*CREATION OF NEW NODE*/
struct node *create_new_node(int i)
{
newptr=(struct node *)malloc(sizeof(struct node));
newptr->info=i;
newptr->link=NULL;
return newptr;
}
/*INSERTION AT BEGINING*/
void insertbeg(struct node *m)
{
if(start==NULL)
{
start=m;
}
else
{
m->link=start;
start=m;
}
}
/*INSERTION AT END*/
void insertend(struct node *n)
{
struct node *temp;
if(start==NULL)
{
start=n;
}
else
{
temp=start;
while(temp->link!=NULL)
temp=temp->link;
temp->link=n;
}
}
/*INSERTION AFTER A GIVEN ELEMENT*/
void insertmid(struct node *o)
{
int value;
struct node *temp;
temp=start;
printf("Enter the number after which ");
printf("new element has to be inserted:\n");
scanf("%d",&value);
while(temp!=NULL)
{
if(temp->info==value)
{
o->link=temp->link;
temp->link=o;
}
temp=temp->link;
}
}
/*DELETE*/
void del(int d)
{
struct node *temp,*ptr;
temp=start;
while(temp!=NULL)
{
if(temp->link->info==d)
{
ptr=temp->link;
temp->link=ptr->link;
free(ptr);
}
temp=temp->link;
}
}
/*REVERSE*/
void reverse(int c)
{
struct node *p1,*p2,*p3;
if(start->link==NULL)
return;
p1=start;
p2=p1->link;
p3=p2->link;
p1->link=NULL;
p2->link=p1;
while(p3!=NULL)
{
p1=p2;
p2=p3;
p3=p3->link;
p2->link=p1;
}
start=p2;
}
/*DISPLAY*/
void display(struct node *x)
{
printf("\nCurrent linked list is:\t");
do
{
printf("%d\t",x->info);
x=x->link;
}
while(x!=NULL);
printf("\n");
}
/*COUNT THE NO. OF NODES*/
int count(struct node *c)
{
int co=0;
do
{
co++;
c=c->link;
}
while(c!=NULL);
return co;
}
























