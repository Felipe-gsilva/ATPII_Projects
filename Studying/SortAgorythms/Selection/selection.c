#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection(int arr[], int length)
{
  int min_index, i = 0, j, aux;
  for (; i < length - 1; i++)
  {
    min_index = i;
    for (j = i + 1; j < length; j++)
    {
      if (arr[j] < arr[min_index])
        min_index = j;
    }
    aux = arr[i];
    arr[i] = arr[min_index];
    arr[min_index] = aux;
  }
}

int main()
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
  selection(list, line_count);

  printf("Array ordenado: \n");
  for (int i = 0; i < line_count; i++)
  {
    printf("%d ", list[i]);
  }
  printf("\n");

  fclose(file);
  free(list);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time: %lf\n", cpu_time_used);
  return 0;
}
