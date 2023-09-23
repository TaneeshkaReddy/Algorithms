#include<stdio.h>
#include<stdlib.h>
int V[100][100],val[100],wt[100];

int max(int a,int b)
{
  return (a>b)?a:b;
}


int knapsackMF(int i,int j)
{
int value;
 if(V[i][j]==-1)
 {
  if(j<wt[i])
  value=knapsackMF(i-1,j);
  else
  value=max(knapsackMF(i-1,j), val[i]+knapsackMF(i-1,j-wt[i]));

  V[i][j]=value;
 }
 return V[i][j];
}


void main()
{
  int N,W;
  printf("Enter number of items and max weight\n");
  scanf("%d%d",&N,&W);

  printf("Enter the weight of items with corresponding values\n");
  for(int i=1;i<=N;i++)
  {
    scanf("%d%d",&wt[i],&val[i]);
  }
  //display input table
printf("item\tvalue\tweight\n");
for(int i=1;i<=N;i++)
  {
    printf("%d\t%d\t%d\n",i,val[i],wt[i]);
  }
//initialise all elements with -1 except first row and first column
  for(int i=0;i<=N;i++)
   {
    for(int j=0;j<=W;j++)
    {
      if(j==0||i==0)
      V[i][j]=0;
      else
      V[i][j]=-1;
    }
   }
   

  int ans =knapsackMF(N,W);
 printf("\n");
  for(int i=0;i<=N;i++)
   {
    for(int j=0;j<=W;j++)
    {
      printf("%d\t",V[i][j]);
    }printf("\n");
   }
   printf("\n");
  printf("Optimal knapsack value: %d\n",ans);
  int RC=W;
  for(int i=N;i>=1;i--)
  {
    if(V[i][RC] != V[i-1][RC])
    {
      printf("%d,\t",i);
      RC=RC-wt[i];
    }
  }}

