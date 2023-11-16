#include <stdio.h>
#include <math.h>

int contador = 0, igualou = 0;

void preencher_zero(int vetor[], int n)
{
  for (int i = 0; i < n; i++)
    vetor[i] = 0;
}

void entrada(int vetor[])
{
  int qtd_disco;
  scanf(" %d", &qtd_disco);
  while (qtd_disco > 0)
  {
    scanf("%d%*c", &vetor[qtd_disco - 1]);
    qtd_disco--;
  }
}

void pega_temp(int ori[], int *temp, int total_discos)
{
  for (int i = 0; i < total_discos; i++)
  {
    if (ori[i + 1] == 0 || i == total_discos - 1)
    {
      *temp = ori[i];
      ori[i] = 0;
      break;
    }
  }
}

void move_temp(int des[], int temp, int total_discos)
{
  for (int i = 0; i < total_discos; i++)
  {
    if (des[i] == 0)
    {
      des[i] = temp;
      break;
    }
  }
}

int verifica(int vet1[], int vet2[], int n)
{
  int corresponde = 1;

  for (int i = 0; i < n; i++)
  {
    if (vet1[i] != vet2[i])
    {
      corresponde = 0;
      break;
    }
  }

  return corresponde;
}

void hanoi(int d, int ori[], int des[], int aux[], int minimo_jogadas, int total_discos, int inp_ori[], int inp_des[], int inp_aux[])
{
  int temp;
  if (!igualou)
  {
    if (verifica(ori, inp_ori, total_discos) && verifica(des, inp_des, total_discos) && verifica(aux, inp_aux, total_discos))
      igualou = 1;
  }
  if (d == 1)
  {
    pega_temp(ori, &temp, total_discos);
    move_temp(des, temp, total_discos);
    if (!igualou)
    {
      if (verifica(ori, inp_ori, total_discos) && verifica(des, inp_des, total_discos) && verifica(aux, inp_aux, total_discos))
        igualou = 1;
    }
    else
      return;

    contador++;
    if (contador == minimo_jogadas)
    {
      return;
    }
  }
  else
  {
    hanoi(d - 1, ori, aux, des, minimo_jogadas, total_discos, inp_ori, inp_aux, inp_des);
    pega_temp(ori, &temp, total_discos);
    move_temp(des, temp, total_discos);
    if (!igualou)
    {
      if (verifica(ori, inp_ori, total_discos) && verifica(des, inp_des, total_discos) && verifica(aux, inp_aux, total_discos))
        igualou = 1;
    }
    else
      return;

    contador++;
    if (contador == minimo_jogadas)
    {
      return;
    }
    hanoi(d - 1, aux, des, ori, minimo_jogadas, total_discos, inp_aux, inp_des, inp_ori);
  }
}

int main()
{
  int n, x;

  scanf(" %d", &n);
  x = pow(2, n) - 1;

  int torre1[n], torre2[n], torre3[n], inp1[n], inp2[n], inp3[n];

  preencher_zero(torre1, n);
  preencher_zero(torre2, n);
  preencher_zero(torre3, n);
  preencher_zero(inp1, n);
  preencher_zero(inp2, n);
  preencher_zero(inp3, n);

  for (int i = 0; i < n; i++)
    torre1[i] = n - i;

  entrada(inp1);
  entrada(inp2);
  entrada(inp3);

  hanoi(n, torre1, torre3, torre2, x, n, inp1, inp3, inp2);

  printf("%d\n", x - contador);
}