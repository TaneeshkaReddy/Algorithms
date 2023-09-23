#include<stdio.h>
#include<stdlib.h>
int opc=0;

int* insertsort(int* a,int n)
{
  int temp,j;
  for(int i=1;i<n;i++)
  {
   temp=a[i];
   j=i-1;
   while(j>=0 && a[j]>temp)
   {
    opc++;
    a[j+1]=a[j];
    j--;
   }
   j++;
   a[j]=temp;
  }
  return a;
}

int main()
{
  //best case input = ascending to sort in ascending order = O(n)
  //worst case = uska reverse = O(n^2)
  int n;
  printf("Enter array size\n");
  scanf("%d",&n);
  int *a=(int*)malloc(sizeof(int)*n);
  printf("Enter array elements\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }

  a=insertsort(a,n);
  
  printf("After sorting,array is:\n");
  for(int i=0;i<n;i++)
  {
    printf("%d\n",a[i]);
  }
  printf("Op count = %d",opc);
return 0;
}