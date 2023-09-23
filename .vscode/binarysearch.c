#include<stdio.h>
#include<stdlib.h>

int* sort(int*,int);
int binarysearch(int*,int,int);


void main()
{
  int key;
  
  
  for(int j=10;j<=50;j=j+10)
  {int count1=0,count2=0,count3=0;
  
  
  printf("\n\nfor n=%d\n",j);
  int* a=(int*)malloc(sizeof(int)*j);
  printf("Enter array elements\n");
  for(int i=0;i<j;i++)
  {
    a[i]=rand();
  }
  a=sort(a,j);
  // for(int i=0;i<j;i++)
  // {
  // printf("%d\n",a[i]);
  // }


  printf("a[best]=%d\n",a[(j-1)/2]);
  printf("a[avg]=%d\n",a[(j)/4]);
  printf("a[worst]=%d\n",a[0]);

  //best case
  key=a[(j-1)/2];
  count1=binarysearch(a,j,key);

//avg case
key=a[(j)/4];
count2=binarysearch(a,j,key);
  
//worst case
key=a[0];
count3=binarysearch(a,j,key);

printf("%d %d %d %d \n",j,count1,count2,count3);
  //  printf("%d %d %d \n",j,count1,count3);



  }
  }

  int* sort(int *a,int n)
  {
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-i-1;j++)
      {
        if(a[j]>a[j+1])
        {
          int temp=a[j];
          a[j]=a[j+1];
          a[j+1]=temp;

        }
      }
    }
    return a;
  }

  int binarysearch(int* a,int j,int key)
  { int count=0;
    int l=0,h=j-1;
    
  while(l<=h)
  {
    count++;
    int m=(l+h)/2;
    if(a[m]==key)
    {
      printf("Key found\n");
      break;
    }
    else if(a[m]<key)
    {
      l=m+1;
    }
    else{
      h=m-1;
    }
  }
  return count;
  }