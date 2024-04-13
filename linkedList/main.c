#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

int tamanhoLista(Node *node) {
  int tam = 1; 
  Node *tempNode = node->proximo;
  if (node == NULL) {
    return 0;
  }
  while (tempNode->proximo != NULL) {
    tempNode = tempNode->proximo;
    tam++;
  }
  return tam;
}

void popularLista(Node **node, int valor) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->valor = valor;
    if (*node == NULL) {
      newNode->proximo = NULL;
      *node = newNode;
    } else {
      newNode->proximo = (*node)->proximo;
      (*node)->proximo = newNode;
    }
}

int mostrarItem(Node *node, int pos) {
    printf("\n PAPAPA PEU");
    int tam = tamanhoLista(node);
    Node *tempNode = node;
    if (pos > tam || pos < 0) {
      return -1;
    }
    for (int i = 0; i < pos; i++) {
      tempNode = tempNode->proximo;
    }
    if (node == NULL) {
      printf("\nPaulo the genius and big man");
    }
    printf("\n EIEIEI PAPAPA PEU");
    return tempNode->valor;
}

int main() {
    Node *ptr = NULL;
    bool programa = false;
    int valor;
    char resposta;
    while (!programa) {
      printf("\nBem Vindo! O que deseja fazer? (A - Adicionar elemento | R - Remover elemento | M - Modificar elemento | L - Listar elemento | T - Listar todos elementos | S - Sair): ");
      scanf(" %c", &resposta);
      switch (resposta) {
	case 'A':
	  printf("\nQual valor voce deseja adicionar? ");
	  scanf("%d", &valor);
	  popularLista(&ptr, valor);
	  printf("\nValor adicionado!");
	  break;
	case 'R':
	  printf("");
	  break;
	case 'M':
	  printf("");
	  break;
	case 'L':
	  printf("\nQual posicao voce deseja listar? ");
	  scanf("%d", &valor);
	  if(ptr == NULL) {
	    printf("FODEU");
	  }
	  int resposta = mostrarItem(ptr, valor);
	  printf("\nChamou ");
	  if (resposta == -1) {
	    printf("\nPosicao invalida! Tente novamente");
	  } else {
	    printf("Pos %d = %d", valor, resposta);
	  }
	  break;
	case 'T':
	  printf("\nAqui estao todos os elementos alocados da lista: ");
	  int tam = tamanhoLista(ptr);
	  for (int i = 0; i < tam; i++) {
	    printf("[%d, %d] -> ", i, mostrarItem(ptr, i));
	  }
	  break;
	case 'S':
	  printf("\nSaindo...");
	  programa = true;
	  break;
	default:
	  printf("\nComando nao existe! Tente novamente");
	  break;
      }
    }
}
