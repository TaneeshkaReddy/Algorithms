#include<stdio.h>
#include<stdlib.h>
int count;

void merge(int *b,int n1,int *c,int n2,int *a)
{
  int i=0,j=0,k=0;
  while(i<n1 && j<n2)
  {
    if(b[i]<=c[j])
    a[k]=b[i++];
    else
    a[k]=c[j++];
    k++;
  }
  if(j==n2)
  {
    while(i<n1)
    a[k++]=b[i++];
  }
  else{
    while(j<n2)
    {
      a[k++]=c[j++];
    }
  }
}

void mergesort(int *a,int n)
{
  int n1,n2,i;
  if(n==1)
  return;
    
      n1=(n-1)/2;
      n2=n-n1;

      int *b=(int*)malloc(sizeof(int)*n1);
      int *c=(int*)malloc(sizeof(int)*n2);
      for(i=0;i<n1;i++)
      {
        b[i]=a[i];
      }
      int k=i;
      for(i=0;i<n2;i++)
      {
       c[i]=a[k];
       k++;
      }

      mergesort(b,n1);
      mergesort(c,n2);
      merge(b,n1,c,n2,a);
   
}

void split(int *a,int left[],int right[],int l,int mid,int r)
{
  for(int i=0;i<=mid-l;i++)
  {
    left[i]=a[i*2];
  }
  for(int i=0;i<r-mid;i++)
  right[i]=a[i*2+1];
}

void join(int *a,int left[],int right[],int l,int mid,int r)
{
  int i,j;
  for(i=0;i<=mid-l;i++)
  a[i]=left[i];
  for(j=0;j<r-mid;j++)
  a[i+j]=right[j];
}

void genworstcase(int *a,int l,int r)
{
  if(l<r)
  {
    int mid=(l+r)/2; 
    int left[mid-l+1];
    int right[r-mid];
    split(a,left,right,l,mid,r);
    genworstcase(left,l,mid);
    genworstcase(right,mid+1,r);
    join(a,left,right,l,mid,r);
  }
}



void main()
{
  int n=8;
  int *a=(int*)malloc(sizeof(int)*n);
  // printf("enter arrar:\n");
  // for(int i=0;i<n;i++)
  // {
  //   scanf("%d",&a[i]);

  // }
  // printf("Array:\n");
  // for(int i=0;i<n;i++)
  // {
  // printf("%d\n",a[i]);

  // }
   


  // mergesort(a,n);
  // printf("after sorting\n");
  // for(int i=0;i<n;i++)
  // {
  // printf("%d\n",a[i]);

  // }

  //worst case - nos. should come both sides

  for(int i=0;i<n;i++)
  a[i]=i+1;

  genworstcase(a,0,n-1);
  printf("after generating worst case array is:\n");
  for(int i=0;i<n;i++)
  {
  printf("%d\n",a[i]);

  }
  mergesort(a,n);


}































// #include<stdio.h>
// #include<stdlib.h>

// int count=0;
// void merge(int *a,int l,int m,int r)
// {
//   count=0;
//   int i=l,j=m+1,k=l;
//   int b[100];
  
  
  
// }


// void mergesort(int *a,int l,int r)
// {
//   if(l<r)
//   {
//     int m=l+(r-l)/2;
//     mergesort(a,l,m);
//     mergesort(a,m+1,r);
//     merge(a,l,m,r);
//   }
// }

// void generateworst(int *a,int n)
// {

//   mergesort(a,0,(n-1)/2);
//   mergesort(a,(n/2),(n-1));

// }


// int main()
// {
//   for(int n=4;n<=128;n=n*2)
//   {
//     int count1=0,count2=0,count3=0;
//     int *a=(int *)malloc(sizeof(int)*n);
//     for(int i=0;i<n;i++)
//     {
//       a[i]=rand()%n;
//     }

//     //avg case:random
//     mergesort(a,0,n-1);
//     count2=count;

//     //best case:sorted array -descending or ascending
//     mergesort(a,0,n-1);
//     count1=count;

//     //worst case-segregate odd and even first
//        int j = -1;
//        // Quick sort method
//        for (int i = 0; i < n; i++) 
//         {
//         // If array of element is odd then swap 
//         if (a[i] % 2 == 0) 
//           {
//             j++;// increment j by one
            
//             int temp=a[j]; // swap the element
//             a[j]=a[i];
//             a[i]=temp;
//         }
//     }
//     generateworst(a,n);
//     mergesort(a,0,n-1);
//     count3=count;

//     printf("\n\n%d\t%d\t%d\t%d",n,count1,count2,count3);
//   }



// }