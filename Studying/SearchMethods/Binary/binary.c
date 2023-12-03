#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void binarysearch(int arr[], int low, int high, int key)
{
  int mid = (low + high) / 2;

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
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
  srand(time(NULL));

  int n = sizeof(arr) / sizeof(arr[0]);
  int key = rand() % 10;
  printf("Key: %d\n", key);
  print_arr(arr, n);
  binarysearch(arr, 0, n - 1, key);

  return 0;
}
