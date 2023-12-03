#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

void print_arr(char **arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%s ", *(arr + i));
  printf("\n");
}

char *median_of_three(char *a, char *b, char *c)
{
  if ((strcmp(a, b) > 0 && strcmp(a, c) < 0) || (strcmp(a, b) < 0 && strcmp(a, c) > 0))
    return a;
  if ((strcmp(b, a) > 0 && strcmp(b, c) < 0) || (strcmp(b, a) < 0 && strcmp(b, c) > 0))
    return b;
  return c;
}

int partition(char *arr[], int low, int high)
{
  char *pivot = arr[high]; // pivot
  int i = low - 1;         // Index of smaller element

  for (int j = low; j < high; j++)
  {
    if (strcmp(arr[j], pivot) <= 0) // If current element is smaller than the pivot
    {
      i++;                    // increment index of smaller element
      swap(&arr[i], &arr[j]); // swap arr[i] and arr[j]
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(char *arr[], int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

int main()
{
  // declarando vari ́aveis utilizadas (iterations= 1 milhão)
  struct timespec begin, end;
  long seconds, nanoseconds;
  double elapsed;

  srand(time(NULL));
  FILE *stdin;
  stdin = fopen("input.txt", "r");
  int line = 1;
  char c;

  // get how many lines are in the file
  do
  {
    c = fgetc(stdin);
    if (c == '\n')
      line++;
  } while (c != EOF);

  // reset file pointer
  fseek(stdin, 0, SEEK_SET);
  if (line == 1)
  {
    puts("Empty file");
    exit(1);
  }

  printf("Number of lines: %d\n", line);
  char **arr;
  arr = malloc(line * sizeof(char *));
  for (int i = 0; i < line; i++)
    arr[i] = malloc(100 * sizeof(char));

  for (int i = 0; i < line; i++)
    fscanf(stdin, "%s", arr[i]);

  fclose(stdin);
  // anota o tempo de in ́ıcio em begin
  clock_gettime(CLOCK_REALTIME, &begin);
  for (int i = 0; i < 5; i++)
  {

    quickSort(arr, 0, line - 1);
  }
  // anota o tempo de fim em end
  clock_gettime(CLOCK_REALTIME, &end);
  seconds = end.tv_sec - begin.tv_sec;
  nanoseconds = end.tv_nsec - begin.tv_nsec;
  elapsed = seconds + nanoseconds * 1e-9;
  printf("Array after sorting: ");
  print_arr(arr, line);
  printf("Total time measured: %.3f seconds.\n", elapsed);
  printf("Average time per iteration: %.3f seconds.\n", elapsed / 5);

  // free memory
  for (int i = 0; i < line; i++)
    free(arr[i]);
  free(arr);

  return 0;
}
