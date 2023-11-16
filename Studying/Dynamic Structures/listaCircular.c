#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct filas
{
  int valor;
  struct filas *next;

} Node;

void insert(Node **head, int value)
{
  Node *new = malloc(sizeof(Node));
  new->valor = value;
  new->next = NULL;

  Node *cur = *head, *prev = *head;
  if(!(*head))
  {
    *head = new;
    return;
  }
  if((*head)->next == *head)
  {
    new->next = cur;
    
  }

}


int main(){
  Node *head = malloc(sizeof(Node));
  Node *tail = head;
  head->next = NULL;
  tail->next = head;
  return 0;
}