#include<stdio.h>
#include<stdlib.h>

int a[100][100],n,reach[100],recstack[100];
int bflag=0;
int connectflag=0;
int display=0;

void dfs(int v,int p)
{  if(display==1)
   printf("-->%d",(v+1));
  
  reach[v]=1;
  recstack[v]=1;
  for(int w=0;w<n;w++)
  {
    if(a[v][w]==1)
    {
      if(reach[w] && recstack[v])
      {
        bflag++;
      }
      
    }
    if(reach[w]==0 && a[v][w])
    dfs(w,v);
  }
  recstack[v]=0;
}

void DFS()
{
int v;
for(v=0;v<n;v++)
{
  if(!reach[v])
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
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      a[i][j]=0;
    }
  }
  int i,j;
  printf("Enter -1 to exit\n");
  printf("There exists an edge \n"); 
while(i!=-1 && j!=-1)
{
printf("From: ");
scanf("%d",&i);
if(i==-1)
break;
printf("\nTo:");
scanf("%d",&j);
printf("\n");
if(i<=n)
a[i][j]=1;

}

for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d ",a[i][j]);
    }
    printf("\n");
  }


  
bflag=0;
connectflag=0;
DFS();
cycandconnect();


  
}