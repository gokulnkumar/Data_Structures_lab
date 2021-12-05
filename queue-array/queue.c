#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int queue[MAX],front=-1,rear=-1;

void enqueue()
{
int num;
printf("Enter the number to be Enqueued:");
scanf("%d",&num);
if (rear==MAX-1)
{
printf("Queue overflow\n");
return;
}
else
{
if (front==-1)
{
front=front+1;
}
rear=rear+1;
queue[rear]=num;
return;
}
}

void dequeue()
{
int num;
if ((front==-1) || (front>rear))
{
printf("Queue underflow\n");
return;
}
else
{
num=queue[front];
printf("The Element dequeued is %d\n",num);
front=front+1;
return;
}
}

void display()
{
if ((front==-1) || (front>rear))
{
printf("Queue is empty\n");
return;
}
for(int i=front;i<=rear;i++)
{
printf("%d\t",queue[i]);
}
printf("\n");
return;
}

int main()
{
int choice;
printf("Enter your choice:\n");
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


