// linkedlist.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
  int valor;
  struct Node *proximo;
} Node;

int tamanhoLista(Node *node);

int adicionarNode(Node **node, int pos, int valor);

int modificarNode(Node **node, int pos, int valor);

int removerNode(Node **node, int pos);

int mostrarNode(Node *node, int pos);

#endif
