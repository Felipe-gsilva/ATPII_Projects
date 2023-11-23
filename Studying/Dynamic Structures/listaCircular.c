#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct filas
{
  int value;;
  struct filas *next;

} Node;

void insert(Node **head,Node **tail ,int value)
{
  Node *new = malloc(sizeof(Node));
  new->next = NULL;
  new->value = value;

  if(!(*head))
  {
    *head = new;
    *tail = new;
    new->next = *tail;
  }

  Node *temp = *head;
  while(temp->next != *head)
    temp = temp->next;

  temp->next = new;
  *tail = new;
  (*tail)->next = *head;
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

void __remove(Node **head, Node **tail){

  if(!(*head))
    return;
  
  Node *aux = *head;
  if(aux->next == *tail)
    {
      free(aux);
      *head = *tail = NULL;
      return;
    }
  *head = (aux->next);
  (*tail)->next = *head;
  free(aux);
  return;
}


int main(){
  Node *tail = NULL, *head = NULL;
  int input;
  for(int i = 0; i < 876; i++)
    insert(&head, &tail, i);
  

  for(int i = 0; i < 875; i++)
    __remove(&head, &tail);

  show(&head);  
  return 0;
}
