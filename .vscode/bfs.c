#include<stdio.h>
#include<stdlib.h>

int graph[100][100],n,reach[100],temp[100];
int bflag=0;
int connectflag=0;
int display=0;


int f;
int r;

// struct ordinaryqueue
// {
//   int f,r;
//   int a[100];
// };

// typedef struct ordinaryqueue Q;


void enqueue(int data,int *queue)
{
  // if(q->f==-1 && q->r==-1)
  // {
  //   q->f=q->r=0;
  //   q->a[q->r]=data;
  //   return;
  // }
  // q->r++;
  // q->a[q->r]=data;

    if(f==-1 && r==-1)
  {
    f=r=0;
    queue[r]=data;
    return;
  }
  r++;
  queue[r]=data;

  }

void dequeue(int* queue)
{
  if(f > r)
  {
    // printf("-->%d",q->a[q->f]);
    if(display==1)
    printf("-->%c",(queue[f] + 65));
    f=-1;
    r=-1;
    return;
  }

  if(f==0 && r==0)
  {
    // printf("-->%d",q->a[q->f]);
    if(display==1)
    printf("-->%c",(queue[f] + 65));
    f=r=-1;
    return;
  }
  // printf("-->%d",q->a[q->f]);
  if(display==1)
  printf("-->%c",(queue[f] + 65));
  f++;

}

int isEmpty(int *queue)
{
  if((f==-1 && r==-1) || (f >r))
  return 1;
  else
  return 0;
}

void bfs(int v,int *queue)
{
  reach[v]=1;
  enqueue(v,queue);

  while(!isEmpty(queue))
  {
    temp[queue[f]]=1;
  for(int w=0;w<n;w++)
  {
    if(graph[queue[f]][w]==1)
    {
      if(reach[w]==1 && temp[w]==0)
      {
        bflag++;
      }
      else if(reach[w]==0)
      {
        reach[w]=1;
        enqueue(w,queue);
      }
      
    }
   
  }
   dequeue(queue);
  }
}

void BFS(int* queue)
{
int v;
for(v=0;v<n;v++)
{
  if(reach[v]==0)
  {
  connectflag++;
    bfs(v,queue);
    if(display==1)
    printf("\n");
  }
}
}

void cycandconnect(int* queue)
{
  if(bflag==0)
  printf("Graph is not cyclic\n");
  else
  printf("Graph is cyclic\n");


  if(connectflag>1)
  {
  printf("Graph is not connected\n");
  display=1;
  for(int i=0;i<n;i++)
  {
    reach[i]=0;
    temp[i]=0;
  }
  BFS(queue);
  }
  else
  printf("Graph is connected\n");
}

void main()
{
  // Q *q=(Q*)malloc(sizeof(Q));
  int *queue[100];
  f=-1;
  r=-1;

  printf("Enter number of vertices\n");
  scanf("%d",&n);
  // printf("Enter adjacency matrix\n");
  // for(int i=0;i<n;i++)
  // {reach[i]=0;
  //   for(int j=0;j<n;j++)
  //   {
  //     scanf("%d",&graph[i][j]);
  //   }
  // }

  // printf("\nadjacency matrix:\n");
  // for(int i=0;i<n;i++)
  // {
  //   for(int j=0;j<n;j++)
  //   {
  //     printf("%d\t",graph[i][j]);
  //   }
  //   printf("\n");
  // }
  // BFS(queue);
  // cycandconnect(queue);




//   //worst case - dense matrix- all entries except diagonal are 1
  printf("Adjacency matrix for worst case\n");
  for(int i=0;i<n;i++)
  {
    temp[i]=0;
    for(int j=0;j<n;j++)
    {
      if(i==j)
      graph[i][j]=0;
      else
      graph[i][j]=1;
      printf("%d\t",graph[i][j]);
    }
    printf("\n");
  }
  BFS(queue);
  cycandconnect(queue);

  //best case - random array
  printf("Adjacency matrix for best case:\n");
  for(int i=0;i<n;i++)
  {
    reach[i]=0;
    temp[i]=0;
    for(int j=0;j<n;j++)
    {
      if(i==j)
      graph[i][j]=0;
      else
      {
      if((i+j)%2==0)
      graph[i][j]=1;
      else
      graph[i][j]=0;
      }
      printf("%d\t",graph[i][j]);
    }
     printf("\n");
  }

  
bflag=0;
connectflag=0;
BFS(queue);
cycandconnect(queue);


 }