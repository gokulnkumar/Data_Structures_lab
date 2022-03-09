#include<stdio.h>
#include<stdlib.h>

int graph[10][10], visited[10],n,arr[30];
static int k=0,count=0;
void DFS(int);
void DFS(int vertex)
{
	int i,c=0;
	count++;
	printf("%d\t",vertex);
	visited[vertex] = 1;
	for(i=0;i<n;i++)
	{
		if(!visited[i] && graph[vertex][i] == 1)
		{
			arr[++k] = i;
			c=1;
		}
		if(count == n)
		{
			exit(0);
		}
	}
	if(c==1)
	{
		DFS(arr[k]);
	}
	else
	{
		k--;
		DFS(arr[k]);
	}	
}
int main()
{
	int i,j;
	printf("\nEnter the total number of vertices in graph\n");
	scanf("%d",&n);
	printf("\nEnter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(i=0;i<n;i++)
	{
		visited[i] = 0;
	}
	printf("\nDFS traversal is \n");
	DFS(0);
}
