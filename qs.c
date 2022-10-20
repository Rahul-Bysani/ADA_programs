#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 2000
void quicksort(int[],int,int);
int partition(int[],int,int);
void main()
{
	int i,n,a[MAX],ch=1, choice;
	double t;
	clock_t st, et;
	system("clear");
	while(ch)
	{
	  printf("\n 1: Worst case analysis \n 2: Average Case Analysis \n");
	  printf("\n Enter your choice\n");
	  scanf("%d", &choice);
	  switch(choice)
	   {
	    case 1:
		   printf("\n *****Analysis of worst case time complexity of quick is T(n)=bigO(n^2)**** \n");
		   printf("\n ***** And when all the elements are in sorted order******\n");
		   printf("\nEnter the number of elements\n");
		   scanf("%d",&n);
		   for(i=0;i<n;i++)
			a[i] = i+1;

		   printf("The Elements considered for the worst case analysis are \n");
		   for(i=0;i<n;i++)
		     printf("%d ",a[i]);

		   st = clock();
		   quicksort(a,0,n-1);
		   et = clock();
		   printf("\n\nthe sorted array elements are\n\n");
		   for(i=0;i<n;i++)
			printf("%d ",a[i]);
			t=et-st;
		   printf("\n The time taken is %f \n",t/CLOCKS_PER_SEC);
		   break;
	    case 2:
		   printf("\n *****Analysis of Average case time complexity of quick is T(n)=1.38*nlog2(n) Note: 2 indicates base 2 **** \n");
		   printf("\n *** And when all the elements are randomly considered***\n");
		   printf("\nEnter the number of elements\n");
		   scanf("%d",&n);
                  for(i=0;i<n;i++)
			a[i] = rand()%MAX;

		   printf("The Elements considered for the Average case analysis are \n");
		   for(i=0;i<n;i++)
		     printf("%d ",a[i]);

		   st = clock();
		   quicksort(a,0,n-1);
		   et = clock();
		   printf("\n\nThe sorted array elements are\n\n");
		   for(i=0;i<n;i++)
			printf("%d ",a[i]);
			t=et-st;
		   printf("\nThe time taken is %f \n",t/CLOCKS_PER_SEC);
		   break;
	    case 3:
		  printf("\nInvalid Choice \n");
		  break;
	    }
   printf("\n\nDo u wish to continue (0/1)\n");
   scanf("%d",&ch);
  }
}

void quicksort(int a[],int low,int high)
{
	int mid;
	if(low<high)
	{
		mid=partition(a,low,high);
		quicksort(a,low,mid-1);
		quicksort(a,mid+1,high);
	}
}
int partition(int a[],int low,int high)
{
	int key,i,j,temp,k;
	key=a[low];
	i=low+1;
	j=high;
	while(i<=j)
	{
		while(i<=high && key>=a[i])
		i=i+1;
		while(key<a[j])
                   j=j-1;
		if(i<j) 
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else
		{
			k=a[j];
			a[j]=a[low];
			a[low]=k;
		}
	}
	return j;
}

