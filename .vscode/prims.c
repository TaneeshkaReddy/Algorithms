#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int a[40][40],N;

int min(int *key,bool *mstset)
{
  int min=999,minindex;
  for(int i=0;i<N;i++)
  {
    if(!mstset[i] && key[i]<min)
    minindex=i,min=key[i];
  }
  return minindex;
}

void printprims(int *parent)
{
  printf("Edge \tWeight\n");
    for (int i = 1; i < N; i++)
        printf("%d - %d \t%d \n", parent[i]+1, i+1,
               a[i][parent[i]]);
}

void prims()
{
  int parent[N];
  int key[N];
  bool mstset[N];

  for(int i=0;i<N;i++)
  {
  key[i]=999;
  mstset[i]=false;
  }
  key[0]=0;
  parent[0]=-1;

  for(int count=0;count<N-1;count++)
  {
    int u=min(key,mstset);
    mstset[u]=true;

    for(int v=0;v<N;v++)
    {
      if(a[u][v] && !mstset[v] && (a[u][v]<key[v]))
      parent[v]=u,key[v]=a[u][v];
    }
  }
  printprims(parent);
}



void main()
{
printf("Enter number of vertices\n");
scanf("%d",&N);
printf("Enter weight matrix\n");
for(int i=0;i<N;i++)
{
  for(int j=0;j<N;j++)
  {
    scanf("%d",&a[i][j]);
  }
}

prims();

}