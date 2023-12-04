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
  char *pivot = median_of_three(arr[low], arr[(low + high) / 2], arr[high]); // pivot

  if (strcasecmp(pivot, arr[low]) == 0)
    swap(&arr[low], &arr[high]);
  else if (strcasecmp(pivot, arr[(low + high) / 2]) == 0)
    swap(&arr[(low + high) / 2], &arr[high]);

  int i = low - 1; // Index of smaller element

  for (int j = low; j < high; j++)
  {
    if (strcasecmp(arr[j], pivot) <= 0) // If current element is smaller than the pivot
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
  struct timespec begin, end;
  long seconds, nanoseconds;
  double elapsed;
  srand(time(NULL));
  FILE *stdin;
  stdin = fopen("in/rep2000u.txt", "r");
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

  for (int i = 0; i < 5; i++)
  {
    fseek(stdin, 0, SEEK_SET); // reset file pointer
    for (int i = 0; i < line; i++)
      fscanf(stdin, "%s", arr[i]);

    // anota o tempo de inıcio em begin
    clock_gettime(CLOCK_REALTIME, &begin);

    quickSort(arr, 0, line - 1);

    // anota o tempo de fim em end
    clock_gettime(CLOCK_REALTIME, &end);

    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed += seconds + nanoseconds * 1e-9;
  }
  fclose(stdin);
  // anota o tempo de fim em end
  printf("Array after sorting: ");
  print_arr(arr, line);
  printf("Total time measured: %.3f seconds.\n", elapsed);
  printf("Average time per iteration: %.3f seconds.\n", elapsed / 5);
  /*
  FILE *stdout;
  stdout = fopen("output.txt", "a");
  fprintf(stdout, "Single Pivot QuickSort (median of three):\n");
  fprintf(stdout, "  -Total time measured: %.3f seconds.\n", elapsed);
  fprintf(stdout, "  -Average time per iteration: %.3f seconds.\n", elapsed / 5);
  fprintf(stdout, "\n");
  fclose(stdout);
  */
  // free memory
  for (int i = 0; i < line; i++)
    free(arr[i]);
  free(arr);

  return 0;
}
