#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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