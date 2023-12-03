#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10


void merge(int arr[], int low, int mid, int high)
{
  int i, j, k;
  int n1 = mid - low + 1;
  int n2 = high - mid;
  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[low + i];

  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  i = 0;
  j = 0;
  k = low;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }

  while (i < n1)
  {
    arr[k++] = L[i++];
  }

  while (j < n2)
  {
    arr[k++] = R[j++];
  }
}


void mergesort(int arr[], int low, int high)
{

  if (low < high)
  {
    int mid = (low + high) / 2;
    mergesort(arr, low, mid);
    mergesort(arr, mid + 1, high);
    merge(arr, low, mid, high);
  }
}


int main()
{
  int arr[MAX];
  for(int i = 0; i < MAX; i++)
    arr[i] = rand() % 100000;
  mergesort(arr, 0, MAX - 1);
  printf("Sorted array: \n");
  for(int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  return 0;
}
