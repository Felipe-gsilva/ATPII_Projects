#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct idoso
{
  int idade, tempo;
  struct idoso *next;
  struct idoso *prev;
} Idoso;

Idoso *create_node(int idade, int tempo)
{
  Idoso *new_node = (Idoso *)malloc(sizeof(Idoso));
  new_node->idade = idade;
  new_node->tempo = tempo;
  new_node->next = NULL;
  new_node->prev = NULL;
  return new_node;
}

void insert_no_priority(Idoso **head, Idoso **tail, int idade, int tempo)
{
  Idoso *new_node = create_node(idade, tempo);
  if (!(*head))
  {
    *head = new_node;
    *tail = new_node;
    return;
  }
  Idoso *temp = *tail;
  while (temp->prev && (temp->tempo < temp->prev->tempo && temp->prev->idade < 60))
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

void insert_with_priority(Idoso **head, Idoso **tail, int idade, int tempo)
{
  Idoso *new_node = create_node(idade, tempo);
  if (!(*head))
  {
    *head = new_node;
    *tail = new_node;
    return;
  }
  new_node->next = *head;
  (*head)->prev = new_node;
  *head = new_node;
  return;
}

void show(Idoso **head, Idoso **caixa)
{
  if (caixa != NULL)
  {
    printf("%d ", (*caixa)->idade);
  }
  Idoso *temp = *head;
  if (!temp)
    return;
  while (temp)
  {
    printf("%d ", temp->idade);
    temp = temp->next;
  }
  printf("\n");
  return;
}
Idoso *send_to_box(Idoso **head, Idoso **tail, Idoso **caixa)
{
  if (!(*head))
    return NULL;
  Idoso *temp = *head;
  if (!(*caixa))
  {
    *caixa = temp;
    (*caixa)->next = NULL;
    (*caixa)->prev = NULL;
    *head = NULL;
    return *caixa;
  }
  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;
  *caixa = temp;
  (*caixa)->next = NULL;
  return *caixa;
}

int main(void)
{
  int start, end, n, I, T;
  double cpu_time_used;
  Idoso *head = NULL, *tail = NULL, *caixa = NULL, *removed = NULL;
  start = clock();

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d %d", &I, &T);
    (I > 59) ? insert_with_priority(&head, &tail, I, T) : insert_no_priority(&head, &tail, I, T);
    if (i % 3 == 0 || i == 0)
    {
      removed = send_to_box(&head, &tail, &caixa);
    }

  }
  show(&head, &removed);
  end = clock();
  cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("Time: %lf\n", cpu_time_used);
  return 0;
}
