#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

void print_queue(Node **head)
{
  if (!(*head))
  {
    printf("Empty list\n");
    return;
  }
  Node *aux = *head;
  while (aux)
  {
    printf("%d ", aux->value);
    aux = aux->next;
  }
  printf("\n");
  return;
}

void push(Node **head, int value)
{
  Node *new = malloc(sizeof(Node));
  new->value = value;
  new->next = NULL;

  if (!(*head))
  {
    *head = new;
    return;
  }

  Node *aux = *head;
  while (aux->next)
    aux = aux->next;
  aux->next = new;
  return;
}

Node *pop(Node **head)
{

  if (!(*head))
    return NULL;

  Node *aux = *head;
  (*head) = (*head)->next;
  aux->next = NULL;
  return aux;
}

int main()
{
  Node *head = malloc(sizeof(Node));
  head = NULL;
  for (int i = 0; i < 15; i++)
    push(&head, i);

  printf("Lista inicial: ");
  print_queue(&head);
  push(&head, 20);
  printf("\nLista incrementada: ");
  print_queue(&head);
  Node *removed = pop(&head);
  printf("\nPrimeiro elemento removido: ");
  print_queue(&head);
  printf("Removido: ");
  print_queue(&removed);
  return 0;
}
