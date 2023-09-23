#include<stdio.h>
#include<stdlib.h>

int LargestNum(int *a,int l,int h)
{
  if(h-l==1)
  return a[l];
  if(l<h)
  {
    int m=l+((h-l)/2);
    int leftmax=LargestNum(a,l,m);
    int rightmax=LargestNum(a,m+1,h);
    if(leftmax>=rightmax)
    return leftmax;
    else
    return rightmax;
  }
}

int main()
{
  int n;
  printf("Enter array size\n");
  scanf("%d",&n);
  int *a=(int*)malloc(sizeof(int)*n);
  printf("Enter array elements\n");
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  printf("largest num in array is: %d\n",LargestNum(a,0,n));
}
