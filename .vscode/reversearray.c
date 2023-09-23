#include<stdio.h>
int main()
{
  int a[11]={1,2,3,4,5,6,7,8,9,10,11};
  int n=11;
  for(int i=0;i<n/2;i++)
  {
   int temp=a[i];
   a[i]=a[n-i-1];
   a[n-i-1]=temp;
  }
  printf("aRRAY:\n");
  for(int i=0;i<n;i++)
  {
    printf("%d\n",a[i]);
  }
  return 0;
}