#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000

typedef struct node {
  char str[max];
  struct node *next;
} Node;
// ----------------- show function -----------------
void show(Node *head) {
  Node *aux = head;

  if (!head) {
    printf("NULL\n");
    return;
  }
  while (aux) {
    printf("%s ", aux->str);
    aux = aux->next;
  }
  printf("\n");
}
// ------------------------------------------------

// ----------------- push function -----------------
void push(char in[], Node **head) {
  Node *new = malloc(sizeof(Node));
  if (!new) {
    printf("Memory error\n");
    return;
  }
  strcpy(new->str, in);
  new->next = NULL;

  if (!(*head) || strcmp(new->str, (*head)->str) < 0) {
    new->next = *head;
    (*head) = new;
    return;
  }
  if (strcmp(new->str, (*head)->str) == 0) {
    return;
  } else {
    Node *current = *head;
    while (current->next && strcmp(new->str, current->next->str) >= 0) {
      current = current->next;
    }
    if (strcmp(new->str, current->str) == 0)
      return;
    else {
      new->next = current->next;
      current->next = new;
    }
  }
}
// ------------------------------------------------

// ----------------- pop function -----------------
void pop(char in[], Node **head) {
  Node *temp = *head;
  int check = 0;
  if (!(*head)) {
    printf("NULL\n");
    return;
  }

  if (strcmp(temp->str, in) == 0) {
    *head = temp->next;
    free(temp);
    show(*head);
    return;
  }
  while (temp->next && strcmp(temp->next->str, in) != 0) {
    temp = temp->next;
  }
  if (!temp->next) {
    show(*head);
    return;
  }
  Node *aux = temp->next;
  temp->next = temp->next->next;
  free(aux);
  show(*head);
}
// ------------------------------------------------

// main
int main() {
  int N, M, op;
  char in[max];
  Node *head = NULL;

  scanf("%d %d", &N, &M);

  for (int i = 0; i < N; i++) {
    scanf("%s", in);
    push(in, &head);
  }
  for (int i = 0; i < M; i++) {
    scanf("%d", &op);
    switch (op) {
    case 0:
      scanf("%s", in);
      pop(in, &head);
      break;
    case 1:
      scanf("%s", in);
      push(in, &head);
      break;
    case 2:
      show(head);
      break;
    }
  }

  Node *temp;
  while (head) {
    temp = head;
    head = head->next;
    free(temp);
  }
  return 0;
}