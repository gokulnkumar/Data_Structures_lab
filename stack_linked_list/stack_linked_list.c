#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *link;
}*top=NULL;


void push()
{
int value;
struct node *temp;
temp=malloc(sizeof(struct node));
printf("Enter the data to be pushed:");
scanf("%d",&value);
temp->data=value;
temp->link=NULL;
if(top==NULL)
{
top=temp;
return;
}
temp->link=top;
top=temp;
}


void pop()
{
int value;
struct node *temp;
if (top==NULL)
{
printf("\nStack underflow\n");
return;
}
value=top->data;
temp=top;
top=top->link;
printf("\nPopped element is %d\n",value);
free(temp);
}


void display()
{
int value;
struct node *q;
if(top==NULL)
{
printf("\nStack is empty\n");
return;
}
q=top;
printf("Stack elements are:\n");
while(q!=NULL)
{
value=q->data;
printf("%d\t",value);
q=q->link;
}
printf("\n");
}


int main()
{
int choice;
printf("Enter your choice:\n");
while(1)
{
printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
display();
break;
case 4:
exit(0);
default:
break;
}
}
}

