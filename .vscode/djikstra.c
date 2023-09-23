#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int a[40][40],N;

int min(int* dist,bool* sptset)
{
  int min=999,minindex;
   for (int v = 0; v < N; v++)
        if (sptset[v] == false && dist[v] <= min)
            min = dist[v], minindex = v;
 
    return minindex;
}

void print(int* dist)
{
  printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < N; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);

}

void djikstra()
{
  int dist[N];
  bool sptset[N];
  for(int i=0;i<N;i++)
  dist[i]=999,sptset[i]=false;

  dist[0]=0;

  for(int count=0;count<N-1;count++)
  {
    int u=min(dist,sptset);
    sptset[u]=true;
    for(int v=0;v<N;v++)
    {
      if(a[u][v] && !sptset[v] && dist[u]!=999 && dist[u]+a[u][v]<dist[v])
      dist[v]=dist[u]+a[u][v];    }
  }
print(dist);

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

djikstra();

}