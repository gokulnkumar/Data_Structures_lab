#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack[MAX],top=-1;

void push()
{
int num;
printf("Enter the element to be pushed into stack:");
scanf("%d",&num);
if(top==MAX-1)
{
printf("Stack overflow\n");
return;
}
else
{
top=top+1;
stack[top]=num;
return;
}
}

void pop()
{
int num;
if (top==-1)
{
printf("Stack underflow\n");
return;
}
else
{
num=stack[top];
top--;
printf("The element popped is %d\n",num);
return;
}
}

void display()
{
if(top==-1)
{
printf("Stack is empty\n");
return;
}
else
{
printf("The elements of stack are:\n");
for(int i=0;i<=top;i++)
{
printf("%d\t",stack[i]);
}
printf("\n");
}
return;
}

int main()
{
int choice;
printf("Enter your choice:\n");
while(1)
{
printf("\n1.Push\n2.Pop\n3.Display\n4.Quit\n");
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
return 0;
}

