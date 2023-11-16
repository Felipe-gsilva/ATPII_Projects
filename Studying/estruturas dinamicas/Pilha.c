#include <stdio.h>
#include <stdlib.h>

typedef struct pessoa
{
  char nome[50];
  int idade;
  struct pessoa *next;
} Pessoa;

void show(Pessoa **head)
{
  Pessoa *temp = *head;

  while (temp)
  {
    printf("%s %d\n", temp->nome, temp->idade);
    temp = temp->next;
  }
}

void push(Pessoa **head, char nome[], int idade)
{
  Pessoa *temp = malloc(sizeof(Pessoa));
  strcpy(temp->nome, nome);
  temp->idade = idade;
  temp->next = NULL;
  temp->next = *head;
  *head = temp;
  return;
}
Pessoa *pop(Pessoa **head)
{
  if (!head)
  {
    printf("Lista vazia\n");
    return;
  }

  Pessoa *temp = *head;
  *head = temp->next;
  temp->next = NULL;
  return temp;
}

int main()
{
  Pessoa *head = malloc(sizeof(Pessoa));
  head = NULL;

  push(&head, "Joao", 20);
  push(&head, "Maria", 30);
  push(&head, "Taylor", 20);
  push(&head, "Rodolfo", 30);
  show(&head);
  printf("\n");
  Pessoa *removido = pop(&head);
  show(&head);
  return 0;
}