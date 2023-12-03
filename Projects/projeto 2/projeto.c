#include <stdio.h>
#include <stdlib.h>

// função recursiva que retorna o maior valor de n
int maxArr(int **arr, int N, int k, int n, int i, int j)
{
  // declaração de variáveis
  int count = 0, d = 0;
  d = N - n + 1; // d recebe a diferença entre o tamanho da matriz e o tamanho da submatriz
  // verifica a submatriz de tamanho n dentro da matriz de tamanho N
  for (; i < d; i++) // i e j são os índices da posição inicial da submatriz
  {
    for (; j < d; j++)
    {
      for (int x = i; x < n + i; x++) // x e y são os índices da submatriz que percorrem a matriz
      {
        for (int y = j; y < n + j; y++)
        {
          if (arr[x][y] == 0)
            count++;
        }
      }
    }
  }
  // caso base
  // se a quantidade de zeros for menor ou igual a k, retorna n
  if (count <= k)
    return n;
  // se a quantidade de zeros for maior que k, retorna o resultado da função com n - 1
  else
    return maxArr(arr, N, k, n - 1, i, j);
}
// função principal
int main()
{
  // declaração de variáveis
  int N, k;
  // leitura da entrada
  scanf("%d %d", &N, &k);
  // alocação dinâmica da matriz (feita com vetor de ponteiros)
  int **arr = (int **)malloc(N * sizeof(int *));
  for (int i = 0; i < N; i++)
  {
    arr[i] = (int *)malloc(N * sizeof(int));
  }
  // leitura da matriz
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      scanf("%d", &arr[i][j]);
  printf("%d", maxArr(arr, N, k, N, 0, 0));
  // limpeza de memória
  for (int i = 0; i < N; i++)
    free(arr[i]);
  free(arr);
  return 0;
} // final da main