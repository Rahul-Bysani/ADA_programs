#include<stdio.h>
void distance(int,int);
int a[10][10];
void main()
{
	int i,j,n;
	printf("\n Enter the number of vertices in the diagraph:");
	scanf("%d",&n);
	printf("\n Enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
	{
		printf("\n\t the starting vertex is %d\n",i);
			distance(i,n);
		printf("\n \t press enter for other source vertex\n");
	}
}
void distance(int v,int n)
{
	int queue[40],visited[20],dis[20],front,rear,i,j;
	for(i=1;i<=n;i++)
	visited[i]=dis[i]=0;
	front=rear=0;
	queue[rear++]=v;
	visited[v]=1;
	do
	{
		i=queue[front++];
		for(j=1;j<=n;j++)
		if(a[i][j] && !visited[j])
		{
			dis[j]=dis[i]+1;
			queue[rear++]=j;
			visited[j]=1;
			printf("\n\t the vertex %d to %d is of distance=%d\n",v,j,dis[j]);
		}
	}
	while(front<rear);
}
