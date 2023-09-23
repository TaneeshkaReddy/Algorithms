#include<stdio.h>
#include<stdlib.h>
int m;
int n=100;
int count;

void stringmatch(char* T,char* P)
{
  for(int i=0;i<(n-m);i++)
  {
   int j=0;
   while(j<m && P[j]==T[i+j])
   {
     count++;
     j++;
   }
   if(j==m)
   return;
  }
 
}

void main()
{
  char* T=(char*)malloc(sizeof(char)*n);
  for(int i=0;i<n-1;i++)
    {
     T[i]='a';
    }
    T[n-1]='b';
  for(m=10;m<=100;m=m+10)
  { 
    printf("For m=%d\t",m);
    count=0;
    char* P=(char*)malloc(sizeof(char)*m);
    //best case - all same
    for(int i=0;i<m;i++)
    {
     P[i]='a';
    }
    stringmatch(T,P);
     printf("B=%d\t",count);

    //worst case
    count=0;
    for(int i=0;i<m-1;i++)
    {
     P[i]='a';
    }
    P[m-1]='b';
  
  stringmatch(T,P);
  printf("W=%d\n",count);

}}