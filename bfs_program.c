#include<stdio.h>
#include<conio.h>
int graph[20][20],arr[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v)
{
 for(i=1;i<=n;i++)
   if(graph[v][i] && !visited[i])
     arr[++r]=i;
   if(f<=r)
   {
   visited[arr[f]]=1;
   printf("%d\t",arr[f]);
   bfs(arr[f++]);
   }
}
void main()
{
int v;
printf("Enter the no of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
 arr[i]=0;
 visited[i]=0;
}
printf("\nEnter graph data in matrix form:\n");
for(i=1;i<=n;i++)
 for(j=1;j<=n;j++)
  scanf("%d",&graph[i][j]);
printf("\nEnter the starting vertex:");
scanf("%d",&v);
visited[v]=1;
printf("%d",v);
bfs(v);
getch();
}