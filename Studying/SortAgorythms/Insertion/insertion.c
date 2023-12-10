#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion_sort(int arr[], int n)
{
  int i, current, j;
  for (i = 1; i < n; i++)
  {
    current = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > current)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

void print_arr(int *arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d\n", *(arr + i));
}

int main(void)
{
  clock_t start, end;
  double cpu_time_used;
  start = clock();
  FILE *file;
  char c;
  int line_count = 0, *list;
  file = fopen("input.txt", "r");
  do
  {
    c = fgetc(file);
    line_count++;
  } while (c != EOF);

  fseek(file, 0, SEEK_SET);
  if (line_count == 1)
  {
    puts("Empty file");
    exit(1);
  }

  list = malloc(line_count * sizeof(int));
  for (int i = 0; i < line_count; i++)
    fscanf(file, "%d", &list[i]);

  insertion_sort(list, line_count);
  print_arr(list, line_count);

  fclose(file);
  free(list);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time: %lf\n", cpu_time_used);
  return 0;
}