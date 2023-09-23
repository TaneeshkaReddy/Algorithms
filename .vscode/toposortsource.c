#include<stdio.h>
#include<stdlib.h>
int n,G[40][40],indegree[40],inqueue[40];
int Q[40],f=0,r=-1;

void toposort()
{
  int source,num=n,flag=0;
//finding source
while(num>0)
{
  //putting abtak ke saare sources with indegree 0 in queue Q
  for(int i=0;i<n;i++)
  {
    if(indegree[i]==0 && inqueue[i]==0)
    {
      inqueue[i]=1;
      Q[++r]=i;
      flag=1;;
    }
  }
  if(flag==0)
    {
    printf("Not possible\n");
    break;
    }

  source=Q[f++];
  indegree[source]=-1;
  printf("-->%d",source+1);
  num--;
  for(int i=0;i<n;i++)
  {
    if(G[source][i]==1)
    indegree[i]--;
  }
}
}

void main()
{
  printf("Enter the number of vertices\n");
  scanf("%d",&n);
  printf("Enter adjacency matrix\n");
  for(int i=0;i<n;i++)
  {
    indegree[i]=0;
    inqueue[i]=0;
   for(int j=0;j<n;j++)
   {
    scanf("%d",&G[i][j]);
   }
  }

  //calculate indegree
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(G[i][j]==1)
      {
      indegree[j]++;
      }
    }
  }

  toposort();
}