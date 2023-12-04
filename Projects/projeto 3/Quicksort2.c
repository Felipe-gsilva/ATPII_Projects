#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//função de troca de valores
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

// função que retorna o valor do pivô
int partition(char *arr[], int low, int high, int *pi1)
{
  if (strcasecmp(arr[low], arr[high]) > 0)
    swap(&arr[low], &arr[high]);

  // seleciona as extremidades como pivôs
  char *pivot1 = arr[low];
  char *pivot2 = arr[high];

  // índices para manter o controle dos elementos menores e maiores
  int i = low + 1;
  int j = high - 1;
  int k = low + 1;

  // loop para colocar os elementos menores que o pivô1 à esquerda e os maiores que o pivô2 à direita
  while (k <= j)
  {
    if (strcasecmp(arr[k], pivot1) < 0) // se o elemento for menor que o pivô1
    {
      swap(&arr[i], &arr[k]);           // troca o elemento com o elemento na posição i
      i++;
    }
    else if (strcasecmp(arr[k], pivot2) > 0) // se o elemento for maior que o pivô2
    {
      while (strcasecmp(arr[j], pivot2) > 0 && k < j) // enquanto o elemento for maior que o pivô2 e o índice k for menor que o índice j
        j--;
      swap(&arr[k], &arr[j]);                         // troca o elemento com o elemento na posição j
      j--;
      if (strcasecmp(arr[k], pivot1) < 0)             // se o elemento for menor que o pivô1
      {
        swap(&arr[i], &arr[k]);                       // troca o elemento com o elemento na posição i
        i++; 
      }
    }
    k++;
  }
  i--;
  j++;

  swap(&arr[low], &arr[i]);  // troca o pivô1 com o elemento na posição i-1
  swap(&arr[high], &arr[j]); // troca o pivô2 com o elemento na posição j+1

  *pi1 = i;
  return j; // retorna o índice do pivô2
}

void DualPivotQuickSort(char *arr[], int low, int high)
{
  if (low < high) // se o índice low for menor que o índice high
  {
    int pi, pi2;
    pi2 = partition(arr, low, high, &pi);     // chama a função partition e retorna o índice do pivô2
    DualPivotQuickSort(arr, low, pi - 1);     // chama a função DualPivotQuickSort para a parte esquerda do pivô1
    DualPivotQuickSort(arr, pi + 1, pi2 - 1); // chama a função DualPivotQuickSort para a parte entre os pivôs
    DualPivotQuickSort(arr, pi2 + 1, high);   // chama a função DualPivotQuickSort para a parte direita do pivô2
  }
}

int main()
{
  struct timespec begin, end;
  long seconds, nanoseconds;
  double elapsed;
  srand(time(NULL));
  FILE *stdin, *output;
  stdin = fopen("arquivo.input", "r");
  int line = 1;
  char c;

  // conta o número de linhas do arquivo
  do
  {
    c = fgetc(stdin);
    if (c == '\n')
      line++;
  } while (c != EOF);

  // verifica se o arquivo está vazio
  if (line == 1)
  {
    puts("Empty file");
    exit(1);
  }

  // aloca memória para o array
  char **arr;
  arr = malloc(line * sizeof(char *));
  for (int i = 0; i < line; i++)
    arr[i] = malloc(100 * sizeof(char));

  // inicia a repetição para contagem do tempo
  for (int i = 0; i < 5; i++)
  {
    // reseta o ponteiro do arquivo
    fseek(stdin, 0, SEEK_SET); 
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
  // fecha o arquivo
  fclose(stdin);
  printf("Array after sorting: ");
  print_arr(arr, line);
  printf("Total time measured: %.3f seconds.\n", elapsed);
  printf("Average time per iteration: %.3f seconds.\n", elapsed / 5);

 // cria o arquivo de saida
  output = fopen("arquivo.output", "w");
  for (int i = 0; i < line; i++)
    fprintf(output, "%s\n", arr[i]);
  fclose(output);
  // limpa a memória
  for (int i = 0; i < line; i++)
    free(arr[i]);
  free(arr);

  return 0;
}
