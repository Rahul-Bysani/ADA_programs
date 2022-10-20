#include<stdio.h>
#define max 20
#include<stdlib.h>
int a[max][max],n;
void topological_sort();
void main()
{
	int i,j;
	printf("\n enter the number of vertices\n");
	scanf("%d",&n);
	printf("\n enter the adjacency matrix\n");
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	scanf("%d",&a[i][j]);
	topological_sort();
}

void topological_sort()
{
	int v[max],ver[max],i,j,p=1,flag=0;
	for(i=1;i<=n;i++)
	v[i]=0;
	while(p<=n)
	{
		j=1;
		while(j<=n)
		{
			flag=0;
			if(v[j]==0)
			{
				for(i=1;i<=n;i++)

				if((a[i][j]!=0) && (v[i]==0))
				{
					flag=1;
					break;
				}
				if(flag==0)
				{
					v[j]=1;
					ver[p++]=j;
					break;
				}
			}
			j++;
			if(j>n)
			{
				printf("\n topological order is not possible\n");
				exit(0);
			}
		}
	}
	printf("\n topological order obtained is...\n");
	for(i=1;i<p;i++)
	printf("\t%d",ver[i]);
}
