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

int partition(char *arr[], int low, int high, int *pi1)
{
  if (strcasecmp(arr[low], arr[high]) > 0)
    swap(&arr[low], &arr[high]);

  char *pivot1 = arr[low];
  char *pivot2 = arr[high];

  int i = low + 1;
  int j = high - 1;
  int k = low + 1;

  while (k <= j)
  {
    if (strcasecmp(arr[k], pivot1) < 0)
    {
      swap(&arr[i], &arr[k]);
      i++;
    }
    else if (strcasecmp(arr[k], pivot2) > 0)
    {
      while (strcasecmp(arr[j], pivot2) > 0 && k < j)
        j--;
      swap(&arr[k], &arr[j]);
      j--;
      if (strcasecmp(arr[k], pivot1) < 0)
      {
        swap(&arr[i], &arr[k]);
        i++;
      }
    }
    k++;
  }
  i--;
  j++;

  swap(&arr[low], &arr[i]);
  swap(&arr[high], &arr[j]);

  *pi1 = i;
  return j;
}

void DualPivotQuickSort(char *arr[], int low, int high)
{
  if (low < high)
  {
    int pi, pi2;
    pi2 = partition(arr, low, high, &pi);
    DualPivotQuickSort(arr, low, pi - 1);
    DualPivotQuickSort(arr, pi + 1, pi2 - 1);
    DualPivotQuickSort(arr, pi2 + 1, high);
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

    DualPivotQuickSort(arr, 0, line - 1);

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
  fprintf(stdout, "Dual Pivot Quick Sort:\n");
  fprintf(stdout, "  -Total time measured: %.3f seconds.\n", elapsed);
  fprintf(stdout, "  -Average time per iteration: %.3f seconds.\n", elapsed / 5);
  fprintf(stdout, "\n\n");
  fclose(stdout);
  */
  // free memory
  for (int i = 0; i < line; i++)
    free(arr[i]);
  free(arr);

  return 0;
}
