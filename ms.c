#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define MAX 2000

void mergesort(int[],int,int);
void merge(int[],int,int,int);

void main()
{
 int ch=1;
 double t;
 int n,i,a[MAX],low,high;
 clock_t begin,end;
 system("clear");
 srand(time(NULL));
 
 while(ch)
 {
  printf("\nEnter the no. of ele\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
   a[i]=rand()%MAX;
   printf("\nThe elements of the array randamly generated are\n");
  for(i=0;i<n;i++)
   printf("%d ", a[i]);
   low=0;high=n-1;
   begin=clock();
   mergesort(a,low,high);
   end=clock();
   printf("\nSorted elements after applying merge sort\n");
  for(i=0;i<n;i++)
   printf("%d ",a[i]);
   double t=end-begin;
  printf("\nTime taken is %lf seconds\n",t/CLOCKS_PER_SEC);
  printf("\nDo you wish to run again(1/0)\n");
  scanf("%d",&ch);
  }
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
  while((i<=mid)&&(j<=high))
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
