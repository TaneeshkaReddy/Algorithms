// DFS, cyclicity & connectivity using DFS
// graph implemented by adj matrix

#include<stdio.h>
#include<stdlib.h>

int n,i,j,k, acyclic=1, connected=1;
/////////  Graph Creation //////////
void printGraphMatrix(int (*a)[n]);

void createGraph(int (*a)[n]);

////////  DFS Traversal & Connectivity //////////
void DFS(int (*a)[n],int v[], int[], int);
void checkConnectivity(int (*a)[n],int v[], int[]);

int main()
{
    
    printf("Enter the number of vertices in the graph:\t");
    scanf("%d",&n);
    
    int a[n][n]; 
    int v[n], vtxInDegree[n], vtxOutDegree[n], recursionStack[n];

    for(int m=0; m<n; m++)
    {
        v[m] = vtxOutDegree[m] = vtxOutDegree[m] = recursionStack[m] = 0;
    }

    createGraph(a);
    printGraphMatrix(a);
    
    printf("\n**********  DFS Traversal  ***********\n");
    printf("\nEnter the starting vertex for DFS traversal:\t");
    scanf("%d",&k);
    k--;
    if(k>=n || k<0)
    {
        printf("\nEnter a valid vertex to begin with....\n");
        exit(0);
    }    
    DFS(a,v,recursionStack,k);
    
    checkConnectivity(a,v,recursionStack);
    
    if(acyclic)
      printf("\nThe graph is acyclic...\n");
      
    else
      printf("\nThe graph is cyclic...\n");
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

void createGraph(int (*a)[n])
{
    for(i = 0; i<n; i++)     
    {
        for(j = 0; j<n; j++) 
        a[i][j] = 0;
    }
    printf("\n%d\t%d\n",i,j);
    
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
        }
    }
}

void DFS(int (*a)[n],int v[], int recursionStack[], int k)
{
    if(!v[k])
    {
        printf("\nVertex %d visited.\n", k+1);
        v[k] = 1;
        recursionStack[k] = 1;
        for (int j = 0; j < n; j++)
        {
            if(a[k][j])
            {
                if(v[j] && recursionStack[j])
                   acyclic=0;
                   
                else
                   DFS(a,v,recursionStack,j);
            }
        }
        recursionStack[k] = 0;
    }
}    
    
void checkConnectivity(int (*a)[n], int v[], int recursionStack[])
{
    for(int i=0; i<n; i++)
    {
       recursionStack[i] = 0;    
       v[i] = 0;
    }
    
    printf("\nChecking connectivity from vertex 1...\n");
    DFS(a,v,recursionStack,0);
    
    for(i=0; i<n; i++)
        if(!v[i])
           connected = 0;
    
    if(!connected)
    {
        int component=1;
        printf("\nThe graph is not connected!!\n");
        
        for(i=0; i<n; i++)
           v[i]=0;
        
        for(i=0; i<n; i++)
           if(!v[i])
           { 
               printf("\nComponent %d\n",component++); 
               DFS(a,v,recursionStack,i);
           }
    }
    
    else
       printf("\nThe graph is connected...\n");
}


