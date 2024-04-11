#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
    int valor;
    lista *proximo;
} lista;

void popularLista(lista *input, int valor) {
    lista *novo = (lista*) malloc(sizeof(lista));
    input->proximo = novo;
}

int main() {
    lista listaTeste = {1, NULL};
    popularLista(&listaTeste, 10);
    printf("%d", listaTeste.);
}