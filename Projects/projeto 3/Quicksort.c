#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// função de troca de valores
void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

// função de impressão do array
void print_arr(char **arr, int n)
{
  for (int i = 0; i < n; i++)
    printf("%s ", *(arr + i));
  printf("\n");
}

// função de mediana de três
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
  // verifica se o pivô é o primeiro elemento
  if (strcasecmp(pivot, arr[low]) == 0)
    swap(&arr[low], &arr[high]);
  // verifica se o pivô é o elemento do meio
  else if (strcasecmp(pivot, arr[(low + high) / 2]) == 0)
    swap(&arr[(low + high) / 2], &arr[high]);

  int i = low - 1; // Índice do elemento menor

  for (int j = low; j < high; j++)
  {
    // Se o elemento atual for menor que o pivô
    if (strcasecmp(arr[j], pivot) <= 0)
    {
      i++;                    // incrementa o índice do elemento menor
      swap(&arr[i], &arr[j]); // troca arr[i] e arr[j]
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Função para realizar a ordenação rápida
void quickSort(char *arr[], int low, int high)
{
  if (low < high)
  {
    // Realiza a partição
    int pi = partition(arr, low, high);

    // Ordena os elementos antes e depois da partição
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

// Função principal
int main(int argc, char *argv[])
{
  struct timespec begin, end;
  long seconds, nanoseconds;
  double elapsed;
  srand(time(NULL));
  int line = 1;
  char c;
  FILE *stdinput, *output;

  stdinput = fopen(argv[1], "r");

  // conta o número de linhas do arquivo
  do
  {
    c = fgetc(stdinput);
    if (c == '\n')
      line++;
  } while (c != EOF);
  if (line == 1)
  {
    puts("Empty file");
    exit(1);
  }
  // aloca memória para o array
  char **arr;
  arr = malloc(line * sizeof(char *));
  for (int i = 0; i < line; i++)
    arr[i] = malloc(36 * sizeof(char));

  //
  for (int i = 0; i < 5; i++)
  {
    fseek(stdinput, 0, SEEK_SET); // reseta o ponteiro do arquivo
    for (int i = 0; i < line; i++)
      fscanf(stdinput, "%s", arr[i]);

    // inicio do clock
    clock_gettime(CLOCK_REALTIME, &begin);

    quickSort(arr, 0, line - 1);

    // fim do clock
    clock_gettime(CLOCK_REALTIME, &end);

    seconds = end.tv_sec - begin.tv_sec;
    nanoseconds = end.tv_nsec - begin.tv_nsec;
    elapsed += seconds + nanoseconds * 1e-9;
  }

  fclose(stdinput);
  printf("Array after sorting: ");
  print_arr(arr, line);
  printf("Total time measured: %.3f seconds.\n", elapsed);
  printf("Average time per iteration: %.3f seconds.\n", elapsed / 5);

  // cria o arquivo de output
  output = fopen("arquivo.output", "w");
  for (int i = 0; i < line; i++)
    fprintf(output, "%s\n", arr[i]);
  fclose(output);
  // free memory
  for (int i = 0; i < line; i++)
    free(arr[i]);
  free(arr);
  return 0;
}
