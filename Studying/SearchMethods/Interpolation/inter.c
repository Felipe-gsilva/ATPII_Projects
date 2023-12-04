#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarysearch(int arr[], int low, int high, int key)
{
  int mid = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

  if (low > high)
  {
    printf("Element not found!\n");
    return;
  }

  if (arr[mid] == key)
  {
    printf("Element found at index %d\n", mid);
    return;
  }
  else if (arr[mid] > key)
  {
    binarysearch(arr, low, mid - 1, key);
  }
  else
  {
    binarysearch(arr, mid + 1, high, key);
  }
}
void print_arr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int arr[30];
  for(int i = 0; i < 30; i++)
    arr[i] = i + 1;

  srand(time(NULL));

  int n = sizeof(arr) / sizeof(arr[0]);
  int key = (rand() % 10) + 1;
  printf("Key: %d\n", key);
  print_arr(arr, n);
  binarysearch(arr, 0, n - 1, key);

  return 0;
}
