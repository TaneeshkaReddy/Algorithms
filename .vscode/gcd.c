#include<stdio.h>
#include<stdlib.h>

int em1(int,int);
int em2(int,int);
int em3(int,int);

void main()
{
  int a,b,c,d,e;
  printf("Enter 2 positive number to obtain gcd\n");
  scanf("%d%d",&a,&b);

  
  c=em1(a,b);
  printf("GCD by method1:%d\n",c);
  
  d=em2(a,b);
  printf("GCD by method 2:%d\n",d);
 
  e=em1(a,b);
   printf("GCD by method 3:%d\n",e);
}

int em1(int m,int n)
{
  int count=0;
  while(n!=0)
  {
    count++;
    int rem=m%n;
    m=n;
    n=rem;
  }
  printf("count1 : %d\n",count);
  return m;
}

int em2(int m,int n)
{
  int count=0;
  while(m!=n)
  {
    count++;
    if(m>n)
    {
      m=m-n;
    }
    else
    n=n-m;
  }
  printf("Count2:%d\n",count);
  return m;
}

int em3(int m,int n)
{
  int t;
  if(m>n)
  {
    t=n;
  }
  else{
    t=m;
  }
  int count=0;
  while(t!=1)
  {
    count++;
    int t1=m%t;
    if(n==0)
    {
      int t2=n%t;
      if(t2==0)
      {
        return t;
      }
    }
    t=t-1;
  }
  printf("count3:%d\n",count);
  return t;
}