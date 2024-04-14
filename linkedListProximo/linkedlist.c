#include <stdlib.h>
#include "linkedlist.h"

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
    if (pos == 0) {
	newNode->proximo = nodeAnterior;
	*node = newNode;
	return 1;
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
