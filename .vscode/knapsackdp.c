#include<stdio.h>
#include<stdlib.h>
int V[100][100],val[100],wt[100];

int max(int a,int b)
{
  return (a>b)?a:b;
}

void knapsack(int N,int W)
{
   for(int i=0;i<=N;i++)
   {
    for(int j=0;j<=W;j++)
    {
      if(i==0||j==0)
      V[i][j]=0;
      else if(j<wt[i])
        V[i][j]=V[i-1][j];
      else
        V[i][j]=max(V[i-1][j], val[i]+V[i-1][j-wt[i]]);
        // V[i][j]=( (V[i-1][j]) > (val[i]+V[i-1][j-wt[i]]) ) ? (V[i-1][j]) : (val[i]+V[i-1][j-wt[i]]);
      }
    }
   
  
   for(int i=0;i<=N;i++)
   {
    for(int j=0;j<=W;j++)
    {
      printf("%d\t",V[i][j]);
    }printf("\n");
   }

   //print opt set and max knapsack value:
  printf("Optimal knapsack value: %d\n",V[N][W]);
  int RC=W;
  int j=0;
  for(int i=N;i>=1;i--)
  {
    if(V[i][RC] != V[i-1][RC])
    {
      printf("%d,\t",i);
      RC=RC-wt[i];
    }
  }
}



void main()
{
  int N,W;
  printf("Enter number of items and max weight\n");
  scanf("%d%d",&N,&W);

  printf("Enter the weight of items with corresponding values\nn");
  for(int i=1;i<=N;i++)
  {
    scanf("%d%d",&wt[i],&val[i]);
  }
printf("item\tvalue\tweight\n");
for(int i=1;i<=N;i++)
  {
    printf("%d\t%d\t%d\n",i,val[i],wt[i]);
  }

  knapsack(N,W);

}