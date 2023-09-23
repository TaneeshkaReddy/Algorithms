// BFS, cyclicity & connectivity using BFS
// graph implemented by adj matrix

#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

int n,i,j,k, acyclic = 1, connected = 1;
/////////  Graph Creation //////////
void printGraphMatrix(int (*a)[n]);

void createGraph(int (*a)[n], int[]);

///////// BFS Traversal  //////////
void bfs(int (*a)[n], int[], int[], int);

void checkConnectivity(int (*a)[n], int[]);

int main()
{
    
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    
    int a[n][n], vtxIndegree[n];

    for(int i = 0; i<n; i++)
       vtxIndegree[i] = 0;
       
    createGraph(a, vtxIndegree);
    printGraphMatrix(a);
    
    checkConnectivity(a, vtxIndegree);
    
    if(acyclic)
      printf("\nAcyclic\n");
      
    else
      printf("\nCyclic\n");
    
    return 0;
}

void printGraphMatrix(int (*a)[n])
{
    printf("\nAdjacent Matrix....\n");
    for(i = 0; i<n; i++)
    {
        for(j=0; j<n; j++)
        printf("%d  ",a[i][j]);
        printf("\n");
    }
}

void createGraph(int (*a)[n], int vtxIndegree[])
{
    for(i = 0; i<n; i++)     
    {
        for(j = 0; j<n; j++)   // initializing each value to zero
        a[i][j] = 0;
    }
    
    while(i != -1 || j != -1)
    {
        printf("\nEnter '-1' to stop !!\n");
        printf("An edge exists from: "); scanf("%d",&i);
        if(i == -1) break;
        printf("                 to: "); scanf("%d",&j);
        i--; 
        j--;
        if(i >= n || j >= n)
        {
            printf("\nEnter valid vertices !!\n");
        }
        else
        {
            a[i][j] = 1;
            vtxIndegree[j]+=1;
        }
    }
}

void checkConnectivity(int (*a)[n], int vtxIndegree[])
{
    int v[n], rs[n], startIndex = 0;
    for(int i = 0; i<n; i++)
    {
        v[i] = rs[i] = 0;
    }
    for(int i = 0; i<n; i++)
       if(vtxIndegree[i] == 0)
       {  
           startIndex = i;
           break;
       }   
     printf("\nChecking connectivity from vertex %d\n",startIndex+1);      
    
    bfs(a,v,rs,startIndex);
    
    for(int i = 0; i<n; i++)
       if(!v[i])
          connected = 0;
    
    if(connected == 1)
      printf("\nConnected\n");
      
    else
    {
        printf("\nNot connected\n");
        int component = 1;
    
        for(int i =0; i<n;i++)
            v[i] = rs[i] = 0;
            
        for(int i = 0; i<n; i++)
        {
            if(!v[i])
            {
               printf("\nComponent %d\n",component++);
               for(int j = 0; j<n; j++)
                  rs[j] = 0;
                  
                bfs(a,v,rs,i);  
            }
        }
    }
}

void bfs(int (*a)[n], int v[], int rs[], int k)
{
    v[k] = rs[k] = 1;
    printf("\nVertex %d visited\n", k + 1);
    int queue[n], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        queue[i] = 0;

    queue[rear] = k;
    while (front <= rear)
    {
        int currentNode = queue[front];
        for (int i = 0; i < n; i++)
        {
            if (a[currentNode][i])
            {
                if (!v[i])
                {
                    rear += 1;
                    queue[rear] = i;
                    printf("\nVertex %d visited\n", i + 1);
                    v[i] = rs[i] = 1;
                }
                else if (v[i] && rs[i])
                {
                    acyclic = 0;
                }
            }
        }
        front += 1;
    }
}

