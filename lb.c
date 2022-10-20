#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 2000

int pos;
int binsearch(int,int[],int,int,int);
int linsearch(int,int[],int);
void mergesort(int [], int, int);
void merge(int [], int, int, int);

void main()
{
  int ch=1;
 
  int n,i,a[MAX],k,op,low,high,pos;
  clock_t begin,end;
  srand(time(NULL));
  while(ch)
  {
  printf("\n.....MENU.....\n 1.Binary Search\n 2.Linear     Search\n 3.Exit\n");
  printf("\nEnter your choice\n");
  scanf("%d",&op);

  switch(op)
  {
      case 1:printf("\nEnter the number of elements \n");
	     scanf("%d",&n);
	     for(i=0;i<n;i++)
		a[i] = rand()%MAX;

	     printf("The Elements of the array randomly generated are \n");
	     for(i=0;i<n;i++)
		printf("%d ",a[i]);
	     low=0;high=n-1;
	     mergesort(a, low, high);

	     printf("\nsorted elements after applying the mergesort\n");
	     for(i=0;i<n;i++)
		printf("%d ",a[i]);

	     printf("\nEnter the element to be searched\n");
	     scanf("%d",&k); 
                 begin=clock();
	     pos=binsearch(n,a,k,low,high);
	     end=clock();
	     if(pos==-1)
	       printf("\n\n Unsuccessful search");
	     else
	       printf("\n Element %d is found at position %d",k,pos+1);
	       printf("\n Time taken is %f CPU1 cycles\n",((double)end-begin)/CLOCKS_PER_SEC);
	       
	       break;

      case 2:printf("\nEnter the number of elements\n");
	     scanf("%d",&n);
	     for(i=0;i<n;i++)
		a[i] = rand()%MAX;

	     printf("The Elements of the array randomly generated are \n");
	     for(i=0;i<n;i++)
		printf("%d ",a[i]);

	      printf("\nEnter the element to be searched\n");
	      scanf("%d",&k);
	      begin=clock();
	      pos=linsearch(n,a,k);
	      end=clock();
	     if(pos==-1)
		 printf("\n\n Unsuccessful search");
		 printf("\n Element %d is found at position %d",k,pos+1);
	     printf("\n Time taken is %f CPU cycles\n",((double)end-begin)/CLOCKS_PER_SEC);
	   
	     break;
    default:printf("\nInvalid choice entered\n");
	    exit(0);

   }
   printf("\n Do you wish to run again (1/0) \n");
   scanf("%d",&ch);
   }
   
 }

 int binsearch(int n,int a[],int k,int low,int high)
{
     int mid;
    
    mid=(low+high)/2;
    if(low>high)
      return -1;
    if(k==a[mid])
      return(mid);
    else
     if(k<a[mid])
       return binsearch(n,a,k,low,mid-1);
     else
      return binsearch(n,a,k,mid+1,high);
  }

  int linsearch(int n,int a[],int k)
  {
    
    if(n<0)
     return -1;
    if(k==a[n-1])
      return(n-1);
     else
      return linsearch(n-1,a,k);
  }
void mergesort(int a[],int low,int high)
{
	int mid;
	
	if(low<high)
	{
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high)
{
            int i,j,k,t[MAX];
	i=low;
	j=mid+1;
	k=low;
	 while((i<=mid) && (j<=high))
	if(a[i]<=a[j])
	t[k++]=a[i++];
	else
	t[k++]=a[j++];
	while(i<=mid)
	t[k++]=a[i++];
	while(j<=high)
	t[k++]=a[j++];
	for(i=low;i<=high;i++)
	a[i]=t[i];
}
