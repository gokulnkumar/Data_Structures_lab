#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *link;
}*front=NULL,*rear=NULL;


void enqueue()
{
    int value;
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("Enter the data to be enqueued:");
    scanf("%d",&value);
    temp->data=value;
    temp->link=NULL;
    if (front==NULL && rear==NULL)
    {
        front=rear=temp;
        rear->link=front;
        return;
    }
    rear->link=temp;
    rear=temp;
    rear->link=front;
}


void dequeue()
{
    int value;
    struct node *temp;
    if(front==NULL && rear==NULL)
    {
        printf("\nCircular Queue Underflow\n");
        return;
    }
    else if(front==rear)
    {
        temp=front;
        value=temp->data;
        printf("\nDequeued element is %d\n",value);
        free(temp);
        front=rear=NULL;
        return;
    }
    else
    {
        temp=front;
        value=temp->data;
        printf("\nDequeued element is %d\n",value);
        front=front->link;
        rear->link=front;
        free(temp);
        return;
    }
}


void display()
{
    int value;
    struct node *q;
    if(front==NULL && rear==NULL)
    {
        printf("\nCircular Queue is empty\n");
        return;
    }
    q=front;
    printf("\nCircular queue elements are:\n");
    do
    {
        value=q->data;
        printf("%d\t",value);
        q=q->link;
    }while(q!=front);
    printf("\n");
}


int main()
{
    int choice;
    printf("Enter your choice:\n");
    while(1)
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
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
}
