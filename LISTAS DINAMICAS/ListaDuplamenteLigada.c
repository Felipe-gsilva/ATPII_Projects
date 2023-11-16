#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int id;
  struct node *next;
  struct node *prev;
} Node;

void is_bigger()
{
}

void insert_left(Node **head, int input)
{
  Node *new = malloc(sizeof(Node));
  new->id = input;
  new->next = NULL;
  new->prev = NULL;

  if (!(*head))
  {
    *head = new;
    return;
  }

  Node *temp = *head;
  while(temp->next && temp->id < input)
    temp = temp->next;

  if(temp->id == input)
    return;    
  
  if(temp->next == NULL)
  {
    temp->next = new;
    new->prev = temp;
    return;
  }
  return;
}

void insert_right(Node **tail)
{
}

void remove_left(Node **head)
{
}
void remove_right(Node **tail)
{
}

void show(Node **head)
{
  Node *aux = *head;
  while (aux)
  {
    printf("%d ", aux->id);
    aux = aux->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  srand(time(NULL));
  Node *head = malloc(sizeof(Node));
  Node *tail = malloc(sizeof(Node));
  tail = head = NULL;
  int input;

  for (int i = 0; i < 10; i++)
  {
    input = rand() % 100;
    insert_left(&head, input);
  }

  show(&head);
  return 0;
}