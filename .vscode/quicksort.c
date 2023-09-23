#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
int temp=*a;
*a=*b;
*b=temp;
}

int partition(int *a,int l,int h)
{
  int p=a[l];
  int i=l;
  int j=h+1;
  do{
     do{
      i=i+1;
     }while(i<=h && a[i]<p);

     do{
      j--;
     }while(j>=l && a[j]>p);

    swap(&a[i],&a[j]);

  }while(i<j);

   swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    return j;
}

void quicksort(int *a,int l,int h)
{
  if(l<h)
  {
    int s=partition(a,l,h);
    quicksort(a,l,s-1);
    quicksort(a,s+1,h);
  }
}

void main()
{
  int n=10;
  int* a=(int*)malloc(sizeof(int)*n);
  for(int i=n-1;i>=0;i--)
  {
    a[i]=rand()%10+1;

  }
  printf("Array:\n");
  for(int i=0;i<n;i++)
  {
  printf("%d\n",a[i]);

  }

  quicksort(a,0,n-1);
  printf("after sorting\n");
  for(int i=0;i<n;i++)
  {
  printf("%d\n",a[i]);

  }

}