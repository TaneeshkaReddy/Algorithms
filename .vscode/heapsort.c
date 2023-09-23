#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
int n;
int count, count1, count2;
int *H, *H1;

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int *H2)
{
  int pi, pv, ci;
  bool heap;
  for (int i = n / 2; i >= 1; i--)
  {
    pi = i;
    pv = H2[i];
    heap = false;
    while (!heap && 2 * pi <= n)
    {
      ci = 2 * pi;
      if (ci < n)
      {
        if (H2[ci + 1] > H2[ci])
          ci++;
      }
      if (pv > H2[ci])
      {
        count++;
        heap = true;
      }
      else
      {
        H2[pi] = H2[ci];
        pi = ci;
      }
    }
    H2[pi] = pv;
  }
}

void heapsort(int *H2)
{
  heapify(H2);

  for (int i = n; i >= 1; i--)
  {
    // printf("%d\n",H[1]);
    swap(&H2[1], &H2[i]);
    n--;
    heapify(H2);
  }
}

void main()
{
  for (int k = 2; k <= 10; k++)
  {

    count = 0;
    n = ((int)pow(2, k)) - 2;
    printf("For n=%d\t", n);
    int n1 = n;

    H = (int *)malloc(sizeof(int) * n);
    H1 = (int *)malloc(sizeof(int) * n);
    // best case
    for (int i = n; i >= 1; i--)
    {
      H[i] = i;
    }
    // printf("After heap sort\n");

    heapsort(H);
    printf("Best case:%d\t", count);

    // worst case
    n = n1;
    count = 0;

    // printf("Enter elements\n");
    for (int i = 1; i <= n1; i++)
    {
      H1[i] = i;
    }
    // printf("After heap sort\n");
    heapsort(H1);

    printf("Worst Case:%d\n", count);
  }

  // printf("Enter elements\n");
  // for(int i=1;i<=n;i++)
  // scanf("%d",&H[i]);
  // printf("After heap sort\n");
  // H=heapsort(H);
}
