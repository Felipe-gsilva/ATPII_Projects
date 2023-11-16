#include <stdio.h>
#include <stdlib.h>

//struct para criar um nó da pilha
typedef struct node {
  int data;
  struct node *next;
} Node;

//função para conseguir dados do usuário
int getData() {
  int data;
  printf("Digite o valor do elemento: ");
  scanf("%d", &data);
  return data;
}

//função para inserir um elemento no início da lista
Node* push(Node *head) {
  Node *node = malloc(sizeof(Node));
  if(node) {
    node->data = getData();
    node->next = head;
    return node;
  } else {
    printf("Erro ao alocar memória\n");
    return NULL;
  }
}

//função para remover um elemento no inicio da lista
Node* pop(Node *head) {
  if(head) {
    Node *rm = head;
    head = head->next;
    free(rm);
    return head;
  } else {
    printf("Lista vazia\n");
  }
}

//função para imprimir a lista
void printList(Node *head) {
  if(head) {
    Node *aux = head;
    while(aux) {
      printf("%d ", aux->data);
      aux = aux->next;
    }
  } else {
    printf("Lista vazia\n");
  }
}

//função principal
int main() {
  Node *head = NULL;
  int option, test = 1;
  while(test){
    printf("Escolha entre 1 e 4(sair):\n");
    scanf("%d", &option);
    switch (option) {
      case 1:
        head = push(head);
        break;
      case 2:
        head = pop(head);
        break;
      case 3: 
        printList(head);
        break;
      case 4:
        test = 0;
        break; 
    }
  }
  return 0;
}