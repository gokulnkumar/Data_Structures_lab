#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *link;
}*start;


void create(int value)
{
struct node *q,*temp;
temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=NULL;
q=start;
if (q==NULL)
{
start=temp;
}
else
{
while(q->link!=NULL)
{
q=q->link;
}
q->link=temp;
}
}



void insert_at_begin(int value)
{
struct node *temp;
temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=NULL;
temp->link=start;
start=temp;
}




void insert_at_middle(int pos,int value)
{
struct node *q,*temp;
int count=1;
temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=NULL;
q=start;
while(count<pos-1)
{
q=q->link;
count++;
}
temp->link=q->link;
q->link=temp;
}





void insert_at_end(int value)
{
struct node *q,*temp;
temp=malloc(sizeof(struct node));
temp->data=value;
temp->link=NULL;
q=start;
while(q->link!=NULL)
{
q=q->link;
}
q->link=temp;
}

void delete_begin()
{
struct node *temp;
int value;
if(start==NULL)
{
printf("Linked list is empty\n");
return;
}
value=start->data;
printf("Deleted element is :%d\n",value);
temp=start;
start=temp->link;
free(temp);
}

void delete_at_position(int pos)
{
int value,count=1;
struct node *q,*temp;
if(start==NULL)
{
printf("\nLinked list is empty\n");
return;
}
q=start;
if(pos==1)
{
value=temp->data;
start=temp->link;
printf("\nDeleted element is %d\n",value);
free(temp);
return;
}
while(count<pos-1)
{
q=q->link;
count++;
if(q->link==NULL)
{
printf("\nGiven position is not present in the linked list\n");
return;
}
}
temp=q->link;
value=temp->data;
q->link=temp->link;
printf("\nDeleted element is %d\n",value);
free(temp);

}


void delete_at_end()
{
int value;
struct node *q,*temp;
if(start==NULL)
{
printf("\nLinked list is empty\n");
return;
}
q=start;
while(q->link!=NULL)
{
temp=q;
q=q->link;
}
temp->link=NULL;
temp=q;
value=temp->data;
printf("\nDeleted element is :%d\n",value);
free(temp);
}


void display()
{
struct node *q;
q=start;
if (q==NULL)
{
printf("\nLinked list is empty\n");
return;
}
else
{
printf("\nLinked list elements are:\n");
while(q!=NULL)
{
printf("%d\t",q->data);
q=q->link;
}
printf("\n");
}
return;
}

int main()
{
int choice,num,value,pos;
printf("Enter your choice:");
while(1)
{
printf("\n1.Create\n2.Insert at beginning\n3.Insert at a position\n4.Insert at end\n5.Delete at beginning\n6.Delete at a position\n7.Delete at end\n8.Display\n9.Exit\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Enter the number of elements to be inserted:");
scanf("%d",&num);
for(int i=0;i<num;i++)
{
printf("Enter the data:");
scanf("%d",&value);
create(value);
}
break;
case 2:
printf("Enter the data to be inserted:");
scanf("%d",&value);
insert_at_begin(value);
break;
case 3:
printf("Enter the position where data to be inserted:");
scanf("%d",&pos);
printf("Enter the data to be inserted:");
scanf("%d",&value);
insert_at_middle(pos,value);
break;
case 4:
printf("Enter the data to be inserted:");
scanf("%d",&value);
insert_at_end(value);
break;
case 5:
delete_begin();
break;
case 6:
printf("Enter the position where element to be deleted:");
scanf("%d",&pos);
delete_at_position(pos);
break;
case 7:
delete_at_end();
break;
case 8:
display();
break;
case 9:
exit(0);
default:
break;
}
}
}


