// heap sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void heap(int a[], int n)
{
   int i, j, k, temp;
   for (i = 2; i <= n; i++)
   {
      j = i;
      k = j / 2;
      temp = a[j];
      while (k > 0 && a[k] < temp)
      {
         a[j] = a[k];
         j = k;
         k = k / 2;
      }
      a[j] = temp;
   }
}

void heap1(int a[], int n)
{
   int i, j, k, temp;
   for (i = n / 2; i > 0; i--)
   {
      k = i;
      temp = a[k];
      j = 2 * k;
      while (j <= n)
      {
         if (j < n && a[j] < a[j + 1])
         {
            j = j + 1;
         }
         if (temp < a[j])
         {
            a[k] = a[j];
            k = j;
            j = 2 * k;
         }
         else
         {
            break;
         }
      }
      a[k] = temp;
   }
}

void adjust(int a[], int n)
{
   int i = 2, temp = a[1];
   while (i <= n)
   {
      if (i < n && a[i] < a[i + 1])
      {
         i = i + 1;
      }
      if (a[i] > temp)
      {
         a[i / 2] = a[i];
         i = i * 2;
      }
      else
      {
         break;
      }
   }
   a[i / 2] = temp;
}

void main()
{
   int a[10000], n, i, temp, choice;
   clock_t st, et;
   system("clear");
   do
   {
      printf("\nEnter the value of n:\n");
      scanf("%d", &n);
      for (i = 1; i <= n; i++)
      {
         a[i] = n - i;
      }
      printf("\nThe elements of the array are:\n");
      for (i = 1; i < n; i++)
         printf("%d ", a[i]);
      st = clock();
      heap1(a, n);
      for (i = n; i >= 2; i--)
      {
         temp = a[1];
         a[1] = a[i];
         a[i] = temp;
         adjust(a, i - 1);
      }
      et = clock();
      printf("\nThe sorted elements are:\n");
      for (i = 1; i <= n; i++)
         printf("%d ", a[i]);
      double t = (et - st);
      printf("\nTime taken is %lf", t / CLOCKS_PER_SEC);
      printf("\nDo you want to continue press 1 else 0\n");
      scanf("%d", &choice);
   } while (choice);
}
