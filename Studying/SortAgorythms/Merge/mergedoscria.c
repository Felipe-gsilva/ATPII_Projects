#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 25

void mergeSort(int *vetor, int *auxVetor, int limInferior, int limSuperior)
{
  // Define os limites inferiores e superiores dos subvetores
  int primeiroEsquerda, primeiroDireita;
  // Define uma variável auxiliar de iteração e o índice do meio do vetor
  int posicao, meio;
  // Verifica se todos os subvetores tem tamanho 1 ou 0
  // Caso afirmativo, encerra a recursão
  if (limSuperior <= limInferior)
    return;
  // Atribui valor ao meio do vetor
  meio = (limInferior + limSuperior) / 2;
  // Divide recursivamente o vetor na metade
  mergeSort(vetor, auxVetor, limInferior, meio);
  mergeSort(vetor, auxVetor, meio + 1, limSuperior);
  // Atribui dois "ponteiros" ao inicio e ao fim dos subvetores
  primeiroEsquerda = limInferior;
  primeiroDireita = meio + 1;
  // Atribui 0 à variável de iteração
  posicao = 0;
  // Seleciona o menor valor de dois subvetores e o aloca no vetor auxiliar
  while (primeiroEsquerda <= meio && primeiroDireita <= limSuperior)
  {
    if (vetor[primeiroEsquerda] < vetor[primeiroDireita])
    {
      auxVetor[posicao] = vetor[primeiroEsquerda];
      primeiroEsquerda++;
    }
    else
    {
      auxVetor[posicao] = vetor[primeiroDireita];
      primeiroDireita++;
    }
    posicao++;
  }
  // Caso a metade da direita acabe antes
  if (primeiroEsquerda > meio)
  {
    while (primeiroDireita <= limSuperior)
    {
      auxVetor[posicao] = vetor[primeiroDireita];
      primeiroDireita++;
      posicao++;
    }
  }
  else
  {
    // Caso a metade da esquerda acabe antes
    while (primeiroEsquerda <= meio)
    {
      auxVetor[posicao] = vetor[primeiroEsquerda];
      primeiroEsquerda++;
      posicao++;
    }
  }
  // Copia os valores ordenados para o vetro original
  for (posicao = limInferior; posicao <= limSuperior; posicao++)
  {
    vetor[posicao] = auxVetor[posicao - limInferior];
  }
}

int main()
{
  int i, A[TAM], B[TAM];
  srand(time(NULL));
  for (i = 0; i < TAM; i++)
  {
    A[i] = rand() % TAM + 1;
    B[i] = 0;
    printf("%d ", A[i]);
  }
  printf("\n");
  mergeSort(A, B, 0, TAM - 1);
  for (i = 0; i < TAM; i++)
  {
    printf("%d ", A[i]);
  }
  return 0;
}