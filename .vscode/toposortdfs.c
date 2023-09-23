#include<stdio.h>
int s[10],vis[10],pop[10],opc=0,top=-1,n,k=0,a[10][10],acyclic=1;

void dfs(int v);
void connectandcyc();

int main()
{ 
  printf("Enter num of vertices\n");
  scanf("%d",&n);
  printf("Enter adjacency matrix\n");
  for(int i=0;i<n;i++)
  {
    vis[i]=-1;
    for(int j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  int start=1;
  dfs(start);
  connectandcyc();
  printf("Op count:%d\n",opc);
  return 0;
}

void dfs(int v)
{ opc++;
  s[++top]=v;
  int f=0;
  while(top!=-1)
  {
    f=0;
    v=s[top];
    vis[v]=1;

    for(int i=0;i<n;i++)
    {
      if(a[v][i] && vis[i]==1)
      acyclic=0;
      if(a[v][i]&&vis[i]==-1)
      {
        opc++;
        s[++top]=i;
        vis[i]=0;
        f=1;
        break;
      }
    }

    if(f==0)
    {
      opc++;
      vis[s[top]]=2;
      pop[k++]=s[top--];
    }
  }
}

void connectandcyc()
{
  for(int i=0;i<n;i++)
  {
    if(vis[i]==-1 || vis[i]==0)
    {
      dfs(i);
    }
  }
    if(acyclic)
    {
      printf("Top sort:\n");
      for(int i=n-1;i>=0;i--)
      {
        printf("%d ,",pop[i]);
      }
      printf("\n");
    }
    else if(acyclic==0)
    printf("Cycle present ,top sort not poss\n");
  }
