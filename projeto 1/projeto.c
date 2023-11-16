#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxF 16
#define maxI 8

// função printar float
void prtFloat(char fAux[maxF], int count, int dotPoint, int minus) {
  FILE *outF;
  int i, k = count - 1, decimals;
  double result = 0, resultM;
  outF = fopen("reais.dat", "a");

  // verificador de sinal
  if (minus == -1) {
    i = 1;
    count++;
  } else
    i = 0;

  // conversor com ascii
  for (; i < count; i++) {
    fAux[i] == '.' ? i++ : i;
    result = result + pow(10, k) * (fAux[i] - '0');
    k--;
  }

  // regula as casas decimais
  result /= pow(10, count - dotPoint);
  decimals = count - dotPoint - 1;

  result *= minus;
  
  // apresentando o resultado
  resultM = (minus == -1) ? (-1000000 - result) : (1000000 - result);

  switch (decimals) {
  case 1:
    fprintf(outF, "%.1lf\t%.1lf\n", result, resultM);
    break;
  case 2:
    fprintf(outF, "%.2lf\t%.2lf\n", result, resultM);
    break;
  case 3:
    fprintf(outF, "%.3lf\t%.3lf\n", result, resultM);
    break;
  case 4:
    fprintf(outF, "%.4lf\t%.4lf\n", result, resultM);
    break;
  case 5:
    fprintf(outF, "%.5lf\t%.5lf\n", result, resultM);
    break;
  case 6:
    fprintf(outF, "%.6lf\t%.6lf\n", result, resultM);
    break;
  }

  fclose(outF);
}

// função printar int
void prtInt(char iAux[maxI], int count, int minus) {
  FILE *outI;
  int i, k = count;
  float result = 0, resultM;
  outI = fopen("inteiros.dat", "a");
  // verificador de sinal
  if (minus == -1) {
    i = 1;
  } else
    i = 0;

  // conversor com ascii
  for (; i != count; i++) {
    result = result + pow(10, k - 1) * (iAux[i] - '0');
    k--;
  }
  result *= minus;

  // apresentando o resultado
  resultM = (minus == -1) ? (-1000000 - result) : (1000000 - result);
  fprintf(outI, "%.0f\t%.0f\n", result, resultM);
  fclose(outI);
}

// função principal
int main() {
  FILE *in;
  char sAux[maxF], fAux[maxF];
  int dotPoint, minus, check, count;
  in = fopen("entrada.dat", "r");
  // verifica se o arquivo já existe e/ou pode ser lido
  if (in == NULL) {
    puts("Error ");
    exit(1);
  }

  // leitura dos dados do arquivo
  while (!feof(in)) {
    check = 0, count = 0;
    fscanf(in, "%s", sAux); // obtém os valores
    minus = 1;              // reseta o auxiliar de sinal
    for (int i = 0; i < maxF + 1; i++) {
      // verifica se o sinal é negativo
      if (sAux[0] == '-') {
        minus = -1;
        i++;
      }
      // insere os dados coletados em uma string auxiliar
      if (sAux[i] != '\0') {
        fAux[i] = sAux[i];
        count++;
        // verifica a posição do ponto
        if (sAux[i] == '.') {
          check++;
          dotPoint = i;
        }
      }
      // termina o loop caso a entrada seja == '\0'
      else
        break;
    }
    // chama os subprogramas
    check == 0 ? prtInt(sAux, count, minus) : prtFloat(fAux, count, dotPoint, minus);
  }
  // fecha o arquivo e retorna 0
  fclose(in);
  return 0;
}