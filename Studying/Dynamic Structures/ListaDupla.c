#include <stdio.h>

typedef struct Node
{
  int value;
  struct Node *next;
  struct Node *prev;
} Node;


void insert_left(Node **head, Node **tail)
{
    Node *new = malloc(sizeof(Node));
    new->next = new->prev = NULL;

    if(!(*head))
    {
        *head = new;
        *tail = new;
        return;
    }

    Node *temp = *head;

    new->next = temp;
    temp->prev = new;
    *head = new;
    return;
}

void insert_right(Node **head, Node **tail)
{
    Node *new = malloc(sizeof(Node));
    new->next = new->prev = NULL;

    if(!(*tail))
    {
        *head = new;
        *tail = new;
        return;
    }

    Node *temp = *tail;

    new->prev = temp;
    temp->next = new;
    *tail = new;
    return;
}

void show(Node **head)
{
  Node *aux = *head;
  
  while(aux->next != *head)
  {
    printf("%d ", aux->value);
    aux = aux->next;
  }
  printf("%d ", aux->value);
  printf("\n");
}

int main()
{
    Node *head = NULL, *tail = NULL;
    return 0;
}
