#include<stdio.h>
#include<stdlib.h>

int a[100][100],n,reach[100];
int bflag=0;
int connectflag=0;
int display=0;

void dfs(int v,int p)
{  if(display==1)
   printf("-->%d",(v+1));
  
  reach[v]=1;
  for(int w=0;w<n;w++)
  {
    if(a[v][w]==1)
    {
      if(reach[w]==1 && w!=p)
      {
        bflag++;
      }
      
    }
    if(reach[w]==0 && a[v][w]==1)
    dfs(w,v);
  }
}

void DFS()
{
int v;
for(v=0;v<n;v++)
{
  if(reach[v]==0)
  { connectflag++;
    dfs(v,-1);
    if(display==1)
    printf("\n");
  }
}
}

void cycandconnect()
{
if(bflag==0)
  printf("Graph is not cyclic\n");
  else
  printf("Graph is cyclic\n");

  // for(int i=0;i<n;i++)
  // {
  //   if(reach[i])
  //   connectflag++;
  //   }
  
  if(connectflag>1)
  {
  printf("Graph is not connected\n");
  display=1;
  for(int i=0;i<n;i++)
  {
    reach[i]=0;
  }
  DFS();
  }
  else 
  {
  printf("Graph is connected\n");
  
  }
}

int main()
{
  printf("Enter number of vertices\n");
  scanf("%d",&n);
  
  //worst case - dense matrix- all entries except diagonal are 1
  printf("Adjacency matrix for worst case\n");
  for(int i=0;i<n;i++)
  {
    reach[i]=0;
    for(int j=0;j<n;j++)
    {
      if(i==j)
      a[i][j]=0;
      else
      a[i][j]=1;
      printf("%d\t",a[i][j]);
    }
    printf("\n");
  }
  DFS();
  cycandconnect();

  //best case - random array
  printf("Adjacency matrix for best case:\n");
  for(int i=0;i<n;i++)
  {
    reach[i]=0;
    for(int j=0;j<n;j++)
    {
      if(i==j)
      a[i][j]=0;
      else
      {
      if((i+j)%2==0)
      a[i][j]=1;
      else
      a[i][j]=0;
      }
      printf("%d\t",a[i][j]);
    }
     printf("\n");
  }

  
bflag=0;
connectflag=0;
DFS();
cycandconnect();


  
}
