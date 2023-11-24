#include <stdio.h>
#include <stdlib.h>

void sort(long double arr[], int n)
{
  int i, j;
  long double current;
  for (i = 1; i < n; i++)
  {
    current = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > current)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = current;
  }
}

void sort_rest(long double arr[], int n, int k)
{
  int i, j;
  long double current;
  for (i = 1 + k; i < n; i++)
  {
    current = arr[i];
    while (j >= k && arr[j] < current)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = current;
  }
}

void print_arr(long double arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%.3Lf ", arr[i]);
  puts("\n");
}

int main()
{
  int n, k;
  long double *arr;
  scanf("%d %d", &n, &k);
  arr = calloc(n, sizeof(long double));
  for (int i = 0; i < n; i++)
    scanf("%Lf", &arr[i]);

  sort(arr, k + 1);
  sort_rest(arr, n, k);
  print_arr(arr, n);
  free(arr);
  return 0;
}