#include<stdio.h>
#include<stdlib.h>

void insert(int *arr,int *num)
{
int pos,n;
printf("Enter the number to be inserted:");
scanf("%d",&n);
printf("Enter the position to be inserted:");
scanf("%d",&pos);
for(int i=*num;i>=pos;i--)
{
arr[i]=arr[i-1];
}
arr[pos-1]=n;
*num=((*num)+1);
}

void delete(int *arr,int *num)
{
int n;
printf("Enter the element to be deleted:");
scanf("%d",&n);
for(int i=0;i<(*num);i++)
{
if (arr[i]==n)
{
for(int j=i;j<(*(num));j++)
{
arr[j]=arr[j+1];
}
*num=((*num)-1);
return;
}
}

for(int i=0;i<(*(num));i++)
{
printf("%d\n",arr[i]);
}
}

int search(int *arr,int num)
{
int n;
printf("Enter the element to  be searched:");
scanf("%d",&n);
for(int i=0;i<num;i++)
{
if (arr[i]==n)
{
return i;
}
}
return -1;
}

void display(int *arr,int *num)
{
for(int i=0;i<(*num);i++)
{
printf("%d\t",*(arr+i));
}
printf("\n");
}

int main()
{
int arr[10],num,pos,choice;
printf("Enter number of elements in the array:");
scanf("%d",&num);
printf("Enter elements of the array:");
for(int i=0;i<num;i++)
{
scanf("%d",(arr+i));
}
printf("Elements of the array are:\n");
for(int i=0;i<num;i++)
{
printf("%d\n",*(arr+i));
}
printf("\n");
while(1)
{
printf("\n1.Insert\n2.Delete\n3.Search\n4.Quit\n");
printf("Enter your choice:");
scanf("%d",&choice);
switch(choice)
{
case 1:
insert(arr,&num);
printf("Array elements after insertion are:\n");
display(arr,&num);
break;
case 2:
delete(arr,&num);
printf("Array elements after deletion are:\n");
display(arr,&num);
break;
case 3:
pos=search(arr,num);
if (pos>=0)
{
printf("Element is found at position:%d\n",pos+1);
}
else
printf("Element not found\n");
break;
case 4:
exit(0);
default:
continue;
}
}
return 0;
}

