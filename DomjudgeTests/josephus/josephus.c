#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
  int id, k, o, read;
  struct node *next;
} Node;

int main()
{
  int n, k, o, count = 0;
  Node *head, *aux, *prev;

  scanf("%d", &n);

  head = NULL;
  head = malloc(sizeof(Node));

  aux = head;
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &aux->k, &aux->o);

    aux->read = 1;
    aux->id = i + 1;

    if (i == 1)
    {
      head->next = aux;
    }

    aux->next = malloc(sizeof(Node));
    prev = aux;
    aux = aux->next;
  }
  free(aux);

  prev->next = head;
  aux = prev;
  prev = head;
  while (count != n)
  {
    count++;
    for (int i = 0; i < prev->k; i += aux->read)
    {
      aux = aux->next;
    }
    aux->read = 0;

    if (aux->o)
    {
      prev->read = 1;
      prev->o = 0;
      count--;
    }
    if (count == n)
    {
      printf("%d\n", aux->id);
    }
    prev = aux;
  }
  return 0;
}
