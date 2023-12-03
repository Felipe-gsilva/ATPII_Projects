#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000000

void print_arr(int arr[], int size)
{
  for (int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  return;
}

int median3(int a, int b, int c)
{
  if ((a > b) && (a > c))
    return a;
  if ((b > a) && (b > c))
    return b;
  return c;
}

int partition(int arr[], int low, int high)
{
  int pivot = median3(arr[low], arr[(low + high) / 2], arr[high]);
  if (pivot == arr[low])
    swap(&arr[low], &arr[high]);
  else if (pivot == arr[(low + high) / 2])
    swap(&arr[(low + high) / 2], &arr[high]);

  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (arr[j] <= pivot)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}

void quicksort(int arr[], int low, int high)
{
  if (low < high)
  {
    int pivot_index = partition(arr, low, high);
    quicksort(arr, pivot_index + 1, high);
    quicksort(arr, low, pivot_index - 1);
  }
}

int main()
{
  srand(time(NULL));
  double start, end;
  start = clock();

  int arr[MAX];
  for (int i = 0; i < MAX; i++)
    arr[i] = rand() % 100000;

  printf("Unsorted array: \n");
  print_arr(arr, MAX);
  quicksort(arr, 0, MAX - 1);
  printf("Sorted array: \n");
  print_arr(arr, MAX);

  end = clock();
  printf("Time taken: %lf\n", (end - start) / CLOCKS_PER_SEC);

  return 0;
}
