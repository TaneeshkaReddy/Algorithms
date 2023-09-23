#include<stdio.h>
int A[40][40];
int n,count=0;

void Warshall()
{
// for(int i=0;i<n;i++)
// {
//   for(int j=0;j<n;j++)
//   {
//     R[i][j]=A[i][j];
//   }
// }

for(int k=0;k<n;k++)
{
  for(int i=0;i<n;i++)
  {
    if(A[i][k]==1)
    {
    for(int j=0;j<n;j++)
    {
      count++;
      A[i][j]=(A[i][j] | (A[i][k] & A[k][j]));
    }
    }
  }
}

}

void creategraph()
{
  printf("Enter adjacency matrix\n");
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
  Warshall();
  printf("The final Transitive closure graph:\n");
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