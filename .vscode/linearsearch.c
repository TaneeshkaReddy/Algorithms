#include<stdio.h>
#include<stdlib.h>

int main()
{
  int key;
   
  for(int j=10;j<=100;j=j+10)
  {
 int count1=0,count2=0,count3=0;
  printf("\n\nfor n=%d\n",j);
  int* a=(int*)malloc(sizeof(int)*j);
  printf("Enter array elements\n");
  for(int i=0;i<j;i++)
  {
    a[i]=rand();
  }

  
  printf("a[best]=%d\n",a[0]);
  printf("a[avg]=%d\n",a[j/2]);
  printf("a[worst]=%d\n",a[j-1]);

  //best case:
  printf("Enter key to search for best case\n");
  key=a[0];
  for(int i=0;i<j;i++)
  {
    count1++;
    if(key==a[i])
    {
      printf("key found at index %d\n",i);
      break;
    }
  }

  //avg case
  printf("Enter key to search for avg case\n");
  key=a[j/2];
  for(int i=0;i<j;i++)
  {
    count2++;
    if(key==a[i])
    {
      printf("key found at index %d\n",i);
      break;
    }
  }
  

  //worst case
  printf("Enter key to search for worst case\n");
  key=a[j-1];
  for(int i=0;i<j;i++)
  {
    count3++;
    if(key==a[i])
    {
      printf("key found at index %d\n",i);
      break;
    }
  }
  printf("%d %d %d %d \n",j,count1,count2,count3);
  }
}