#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int cirqueue[MAX],front=-1,rear=-1;


void enqueue()
{
int num;
printf("Enter the number to be enqueued:");
scanf("%d",&num);
if (front==(rear+1)%MAX)
{
printf("\nQueue Overflow\n");
return;
}
if (front==-1 && rear==-1)
{
front=0;
rear=0;
}
else if(rear==MAX-1 && front!=0)
{
rear=0;
}
else
{
rear=(rear+1)%MAX;
}
cirqueue[rear]=num;
}


void dequeue()
{
int num;
if (front==-1)
{
printf("\nQueue Underflow\n");
return;
}
num=cirqueue[front];
printf("The elemenet dequeued is %d\n",num);
if (front==rear)
{
front=rear=-1;
}
else if (front==MAX-1)
{
front=0;
}
else
{
front=(front+1)%MAX;
}
return;
}


void display()
{
if (front==-1)
{
printf("\nQueue is empty\n");
return;
}
printf("Elements of queue are:\n");
if (front>rear)
{
for (int i=front;i<MAX;i++)
{
printf("%d\t",cirqueue[i]);
}
for (int i=0;i<=rear;i++)
{
printf("%d\t",cirqueue[i]);
}
}
else
{
for(int i=front;i<=rear;i++)
{
printf("%d\t",cirqueue[i]);
}
}
printf("\n");
}


int main()
{
int choice;
while(1)
{
printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Quit\n");
scanf("%d",&choice);

switch(choice)
{
case 1:
enqueue();
break;
case 2:
dequeue();
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
return 0;
}
