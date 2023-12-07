#include <stdio.h>

void shellSort(int arr[], int n)
{
  int k = 1, current, j;

  while (k <= n / 2)
    k = k * 3 + 1;

  while (k > 0)
  {
    for (int i = k; i < n; i++)
    {
      current = arr[i];
      j = i;
      while (j >= k && arr[j - k] > current)
      {
        arr[j] = arr[j - k];
        j -= k;
      }
      arr[j] = current;
    }
    k = (k - 1) / 3;
  }
}

int main()
{
  int arr[] = {9, 5, 1, 3, 8, 4, 2, 7, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Array antes da ordenação:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  shellSort(arr, n);

  printf("\nArray depois da ordenação:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }

  return 0;
}
