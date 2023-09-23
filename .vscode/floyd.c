#include<stdio.h>
int A[40][40];
int n,count=0;

void Floyd()
{
  for(int k=0;k<n;k++)
{
  for(int i=0;i<n;i++)
  {
    int T=A[i][k];
    for(int j=0;j<n;j++)
    {
      count++;
      if(A[i][j]>T)
      A[i][j]=((T+A[k][j])<A[i][j])?(T+A[k][j]):(A[i][j]);
    }
    }
  }
}



void creategraph()
{
  printf("Enter adjacency matrix with entries as weights enter 999 as infinity:\n");
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      scanf("%d",&A[i][j]);
    }
  }
}


void main()
{
  printf("Enter the number of vertices\n");
  scanf("%d",&n);
  creategraph();
  Floyd();
  printf("The all pairs shortest matrix:\n");
   for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d ",A[i][j]);
    }
    printf("\n");
  }
  printf("Operation count : %d\n",count);
}