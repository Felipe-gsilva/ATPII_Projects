#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct filas
{
  int valor;
  struct filas *next;

} Node;

void insertList(Node **head, int input)
{
  Node *temp = malloc(sizeof(Node));
  temp->valor = input;
  temp->next = NULL;
  if (!(*head))
  {
    temp->next = *head;
    *head = temp;
    return;
  }

  if (input < (*head)->valor)
  {
    temp->next = *head;
    *head = temp;
    return;
  }
  if (temp->valor == (*head)->valor)
  {
    *head = temp->next;
    free(temp);
    return;
  }
  Node *current = *head;
  while (current->next && current->next->valor < input)
    current = current->next;

  temp->next = current->next;
  current->next = temp;
  return;
}

void show(Node **head)
{
  Node *aux = *head;
  while (aux)
  {
    printf("%d ", aux->valor);
    aux = aux->next;
  }
  printf("\n");
}

void pop(Node **head, int input)
{
  if (!head)
  {
    printf("Lista vazia\n");
    return;
  }
  Node *temp = *head;
  while (temp->next && temp->next->valor != input)
    temp = temp->next;

  if (!temp->next)
  {
    printf("Valor nao encontrado\n");
    return;
  }

  Node *aux = temp->next;
  temp->next = aux->next;
  temp = aux;
  free(temp);
  return;
}

int main()
{
  srand(time(NULL));
  Node *head = malloc(sizeof(Node));
  head = NULL;
  int input;
  for (int i = 0; i < 5; i++)
  {
    input = rand() % 1000;
    insertList(&head, input);
  }
  input = 207;
  insertList(&head, input);
  show(&head);

  pop(&head, 207);
  show(&head);

  return 0;
}