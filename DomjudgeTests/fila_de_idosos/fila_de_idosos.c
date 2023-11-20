#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct idoso
{
  int age, time;
  struct idoso *next;
  struct idoso *prev;
} Node;
Node *head = NULL, *tail = NULL, *caixa = NULL, *removed = NULL;
Node *create_node(int age, int time)
{
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->age = age;
  new_node->time = time;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void insert_no_priority(Node **head, Node **tail, int age, int time)
{
  Node *new_node = create_node(age, time);
  if (!(*head))
  {
    *head = new_node;
    *tail = new_node;
    return;
  }
  Node *temp = *tail;
  while (temp->prev && (temp->time < temp->prev->time && temp->prev->age < 60))
    temp = temp->prev;
  if (temp == *tail)
  {
    (*tail)->next = new_node;
    new_node->prev = *tail;
    *tail = new_node;
    return;
  }
  new_node->next = temp;
  new_node->prev = temp->prev;
  temp->prev->next = new_node;
  temp->prev = new_node;
  return;
}

void insert_with_priority(Node **head, Node **tail, int age, int time)
{
  Node *new_node = create_node(age, time);
  if (!(*head))
  {
    *head = new_node;
    *tail = new_node;
    return;
  }

  Node *temp = *head;

  while (temp->age >= 60)
  {
    if (temp->time < new_node->time)
    {
      temp = temp->next;
      printf("temp age:%d\n", temp->age);
    }
  }
  if (temp == *head)
  {
    (*head)->prev = new_node;
    new_node->next = (*head)->next;
    *head = new_node;
    return;
  }
  new_node->prev = temp->prev;
  new_node->next = temp;
  temp->prev = new_node;
  temp = new_node;
  return;

  return;
}

void show(Node **head, int i)
{
  Node *temp = *head;
  if (!temp)
  {
    printf("\n");
    return;
  }
  for (int j = 0; j < i; j++)
  {
    if (temp)
    {
      printf("%d ", temp->age);
      temp = temp->next;
    }
  }
  return;
}

Node *send_to_box(Node **head, Node **tail, Node **caixa, int N)
{
  if (N % 3 == 0)
  {
    Node *temp = *head;
    if (!(*head)->next)
    {
      *caixa = *head;
      *head = NULL;
      *tail = NULL;
      (*caixa)->next = NULL;
      (*caixa)->prev = NULL;
      return *caixa;
    }
    else if ((*head)->next)
    {
      *caixa = *head;
      *head = (*head)->next;
      (*caixa)->next = NULL;
      (*caixa)->prev = NULL;
      return *caixa;
    }
  }
  return *caixa;
}

int main(void)
{
  int n, j = 0, I, T, N;
  scanf("%d", &n);
  N = n * 3;
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &I, &T);
    (I > 59) ? insert_with_priority(&head, &tail, I, T)
             : insert_no_priority(&head, &tail, I, T);
    if (i == 0)
      removed = send_to_box(&head, &tail, &caixa, N - i);
  }
  for (int i = 0; i < n - 1; i++)
  {
    j++;
    if (j == 2)
    {
      removed = send_to_box(&head, &tail, &caixa, N - i);
      j = 0;
    }
    show(&removed, 1);
    show(&head, i);
    puts("\n");
  }

  return 0;
}