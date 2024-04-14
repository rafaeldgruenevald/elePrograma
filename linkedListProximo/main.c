#include "linkedlist.h"
#include <stdbool.h>
#include <stdio.h>

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
