#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
  int data;
  struct node *next;
  struct node *prev;
} Node;

Node *create_new_node(int data)
{
  Node *new_node = malloc(sizeof(Node));
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void insert(Node **head, Node **tail, int data)
{
  Node *new_node = create_new_node(data);

  if (!(*head))
  {
    *head = new_node;
    *tail = new_node;
    return;
  }
  (*tail)->next = new_node;
  new_node->prev = *tail;
  *tail = new_node;
  return;
}

void insertion_sort(Node **head, int n)
{
  int i = 1, key, aux;
  Node *temp = *head;
  while (temp)
  {
    key = temp->data;
    aux = i - 1;
    Node *aux_node = temp->prev;
    while (aux_node && aux_node->data > key)
    {
      aux_node->next->data = aux_node->data;
      aux_node = aux_node->prev;
      aux--;
    }
    if (aux_node)
      aux_node->next->data = key;
    else
      (*head)->data = key;
    temp = temp->next;
    i++;
  }
}

void print_arr(Node **head, int n)
{
  if (!(*head))
    return;
  Node *aux = *head;
  while (aux)
  {
    printf("%d ", aux->data);
    aux = aux->next;
  }
  puts("\n");
}

void free_aux(Node **head)
{
  while (*head)
  {
    Node *aux = *head;
    *head = (*head)->next;
    free(aux);
  }
  return;
}

int main(void)
{
  clock_t start, end;
  double cpu_time_used;
  start = clock();

  srand(time(NULL));
  Node *head = NULL, *tail = NULL;
  int N, data;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
  {
    data = rand() % 100000;
    insert(&head, &tail, data);
  }
  print_arr(&head, N);
  insertion_sort(&head, N);
  print_arr(&head, N);
  free_aux(&head);

  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time: %lf\n", cpu_time_used);
  return 0;
}