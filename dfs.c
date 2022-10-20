#include<stdio.h>
void dfs(int n,int cost[10][10],int u,int s[])
{
	int v;
	s[u]=1;
	for(v=0;v<n;v++)
	{
		if(cost[u][v]==1 && s[v]==0)
		{
			dfs(n,cost,v,s);
		}
	}
}

void main()
{
	int n,i,j,cost[10][10],s[10],connected,flag;
	printf("\n enter the number of nodes\n");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&cost[i][j]);
		}
	}
	connected=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		s[i]=0;
		dfs(n,cost,j,s);
		flag=0;
		for(i=0;i<n;i++)
		{
			if(s[i]==0)
			flag=1;
		}
		if(flag==0)
		connected=1;
	}

	if(connected==1)
	printf("graph is connected\n");
	else
	printf("graph is not connected\n");
}

