#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20

void merge(int arr[], int low, int mid, int high)
{
  int i, j, k;            // contadores
  int n1 = mid - low + 1; // tamanho da parte esquerda
  int n2 = high - mid;    // tamanho da parte direita
  int L[n1], R[n2];       // arrays temporários

  for (i = 0; i < n1; i++) // copia os elementos para o array temporário esquerdo
    L[i] = arr[low + i];

  for (j = 0; j < n2; j++) // copia os elementos para o array temporário direito
    R[j] = arr[mid + 1 + j];

  i = 0;   // contador do array temporário esquerdo
  j = 0;   // contador do array temporário direito
  k = low; // contador do array original

  while (i < n1 && j < n2) // junta as partes
  {
    if (L[i] <= R[j]) // se o elemento da parte esquerda for menor ou igual ao da parte direita
    {
      arr[k++] = L[i++]; // copia o elemento da parte esquerda para o array original
    }
    else // se o elemento da parte direita for menor ou igual ao da parte esquerda
    {
      arr[k++] = R[j++]; // copia o elemento da parte direita para o array original
    }
  }

  while (i < n1) // copia os elementos restantes da parte esquerda
  {
    arr[k++] = L[i++]; // para o array original
  }

  while (j < n2) // copia os elementos restantes da parte direita
  {
    arr[k++] = R[j++]; // para o array original
  }
}

void mergesort(int arr[], int low, int high)
{
  if (low < high)
  {
    int mid = (low + high) / 2;    // encontra o meio
    mergesort(arr, low, mid);      // parte esquerda
    mergesort(arr, mid + 1, high); // parte direita
    merge(arr, low, mid, high);    // junta as partes
  }
}

int main()
{
  srand(time(NULL));
  int arr[MAX];
  for (int i = 0; i < MAX; i++)
    arr[i] = rand() % 100;

  printf("Unsorted array: \n");
  for (int i = 0; i < MAX; i++)
    printf("%d ", arr[i]);

  mergesort(arr, 0, MAX - 1);

  printf("\nSorted array: \n");
  for (int i = 0; i < MAX; i++)
  {
    printf("%d ", arr[i]);
  }
  return 0;
}
