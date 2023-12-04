#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
  int i, current, j; 
  for (i = 1; i < n; i++)
  {
    current = arr[i]; // this variable stores the value of the current element
    j = i - 1; // this variable stores the index of the previous element
    while (j >= 0 && arr[j] > current) // this loop moves the previous elements that are greater than the current element one position ahead of their current position
    {
      arr[j + 1] = arr[j]; // this moves the previous element one position ahead of its current position
      j = j - 1; // this moves the index of the previous element one position ahead of its current position
    }
    arr[j + 1] = current; // this is the correct position of the current element
  }
}

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", *(arr + i));
  puts("\n");
}

int main(void)
{
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  srand(time(NULL));
  int *list, N;
  scanf("%d", &N);
  list = calloc(N, sizeof(int));
  for (int i = 0; i < N; i++)
    *(list + i) = rand() % 100000;
  insertion_sort(list, N);
  print_arr(list, N);
  free(list);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time: %lf\n", cpu_time_used);
  return 0;
}