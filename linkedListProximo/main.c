#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

int tamanhoLista(Node *node) {
    int tam = 1; 
    Node *tempNode = node;
    if (node == NULL) {
	return 0;
    }
    while (tempNode->proximo != NULL) {
	tempNode = tempNode->proximo;
	tam++;
    }
    return tam;
}

int adicionarNode(Node **node, int pos, int valor) {
    int tam = tamanhoLista(*node);
    Node *nodeAnterior = *node;
    Node *nodePosterior = *node;
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->valor = valor;
    if (pos > tam) {
      return -1;
    }
    if (pos == -1) {
	if (*node == NULL) {
	    newNode->proximo = NULL;
	    *node = newNode;
	} else {
	    Node *tempNode = *node;
	    while (tempNode->proximo != NULL) {
		tempNode = tempNode->proximo;
	    }
	    tempNode->proximo = newNode;
	}
	return 1;
    }
    for (int i = 1; i < pos; i++) {
      nodeAnterior = nodeAnterior->proximo;
    }
    nodePosterior = nodeAnterior->proximo;
    nodeAnterior->proximo = newNode;
    newNode->proximo = nodePosterior;
    return 1;
}

int modificarNode(Node **node, int pos, int valor) {
    int tam = tamanhoLista(*node);
    Node *modNode = *node;
    if (pos > tam || pos < 0) {
	return -1;
    }
    for (int i = 0; i < pos; i++) {
	modNode = modNode->proximo;
    }
    modNode->valor = valor;
    return 1;
}

int removerNode(Node **node, int pos) {
    int tam = tamanhoLista(*node);
    Node *nodeAnterior = *node;
    Node *nodePosterior;
    if (pos > tam || pos < 0) {
	return -1;
    }
    // Remover o Head
    if (pos == 0) {
	nodePosterior = nodePosterior->proximo;
	free(*node);
	*node = nodePosterior;
	return 1;
    }
    for (int i = 1; i < pos; i++) {
	nodeAnterior = nodeAnterior->proximo;
    }
    nodePosterior = (nodeAnterior->proximo)->proximo;
    free(nodeAnterior->proximo);
    // Remover o Tail ou valor do meio
    if(pos == (tam - 1)) {
	nodeAnterior->proximo = NULL;
    } else {
	nodeAnterior->proximo = nodePosterior;
    }
    return 1;
}

int mostrarNode(Node *node, int pos) {
    int tam = tamanhoLista(node);
    Node *tempNode = node;
    if (pos > tam || pos < 0) {
	return -1;
    }
    for (int i = 0; i < pos; i++) {
	tempNode = tempNode->proximo;
    }
    return tempNode->valor;
}

int main() {
    Node *head = NULL;
    bool programa = false;
    int valor,pos;
    char resposta;
    while (!programa) {
      printf("\nBem Vindo! O que deseja fazer? (A - Adicionar elemento | R - Remover elemento | M - Modificar elemento | L - Listar elemento | T - Listar todos elementos | S - Sair): ");
      scanf(" %c", &resposta);
      switch (resposta) {
	case 'A':
	  printf("\nQual posicao voce deseja adicionar este valor? (Colocar -1 caso final!)");
	  scanf("%d", &pos);
	  printf("\nQual valor voce deseja adicionar? ");
	  scanf("%d", &valor);
	  adicionarNode(&head, pos, valor);
	  printf("\nValor adicionado!");
	  break;
	case 'R':
	  printf("\nQual posicao voce deseja remover? ");
	  scanf("%d", &pos);
	  resposta = removerNode(&head, pos);
	  if (resposta == -1) {
	      printf("\nPosicao invalida! Tente novamente");
	  } else {
	      printf("\nValor removido!");
	  }
	  break;
	case 'M':
	  printf("\nQual posicao voce deseja modificar? ");
	  scanf("%d", &pos);
	  printf("\nQual valor? ");
	  scanf("%d", &valor);
	  int resposta = modificarNode(&head, pos, valor);
	  if (resposta == -1) {
	      printf("\nPosicao invalida! Tente novamente");
	  } else {
	      printf("\nValor modificado!");
	  }
	  break;
	case 'L':
	  printf("\nQual posicao voce deseja listar? ");
	  scanf("%d", &pos);
	  resposta = mostrarNode(head, pos);
	  if (resposta == -1) {
	      printf("\nPosicao invalida! Tente novamente");
	  } else {
	      printf("[%d, %d]", pos, resposta);
	  }
	  break;
	case 'T':
	  printf("\nAqui estao todos os elementos alocados da lista: ");
	  int tam = tamanhoLista(head);
	  for (int i = 0; i < tam; i++) {
	      printf("[%d, %d] -> ", i, mostrarNode(head, i));
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
