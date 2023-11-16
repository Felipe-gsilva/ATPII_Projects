#include <stdio.h>
#include <stdlib.h>

#define MEM_ALLOC_ERROR -1

typedef struct node
{
  int value;
  struct node *next;
  struct node *prev;
} Node;
Node *create_node(int value)
{
  Node *new = malloc(sizeof(Node));
  new->value = value;
  new->next = NULL;
  new->prev = NULL;
  return new;
}
void insert_head(Node **head, int value, Node **tail)
{

  return;
}

void show_head(Node **head)
{
  if (!(*head))
  {
    printf("Lista vazia\n");
    return;
  }
  Node *aux = *head;
  while (aux)
  {
    printf("%d ", aux->value);
    aux = aux->next;
  }
  printf("\n");
}

void insert_tail()
{
}

int main()
{
  Node *head = malloc(sizeof(Node));
  Node *tail = head;
  if (!head)
    return MEM_ALLOC_ERROR;

  for (int i = 0; i < 10; i++)
    insert_head(&head, i, &tail);

  show_head(&head);

  return 0;
}
