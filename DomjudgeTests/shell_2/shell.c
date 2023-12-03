#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_arr(char **str, int n)
{
  for (int i = 0; i < n; i++)
    printf("%s ", *(str + i));
  puts("\n");
}

void shellsort(char **str, int n)
{
  char *temp;
  temp = malloc(50 * sizeof(char));
  int i, j, L, k;
  k = 1;
  while (k <= n / 4)
    k *= 2;
  while (k != 1)
  {
    k = k / 2;
    for (L = 0; L < k; L++)
    {
      for (i = L + k; i < n; i = i + k)
      {
        strcpy(temp, str[i]);
        j = i;
        while (j - k >= 0 && strcmp(temp, str[j - k]) < 0)
        {
          strcpy(str[j], str[j - k]);
          j = j - k;
        }
        strcpy(str[j], temp);
      }
    }
    print_arr(str, n);
  }
}

int main()
{
  int n, k;
  scanf("%d", &n);

  char **str = (char **)malloc(n * sizeof(char *));
  for (int i = 0; i < n; i++)
    str[i] = malloc(50 * sizeof(char));

  for (int i = 0; i < n; i++)
    scanf("%s", *(str + i));

  shellsort(str, n);
  for (int i = 0; i < n; i++)
    free(str[i]);
    
  free(str);

  return 0;
}
