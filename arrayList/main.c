#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_CAP_SIZE 10

typedef struct ArrayList {
    int *arr;
    int tam;
    int cap;
} ArrayList;

void iniciarArrayList(ArrayList **ptr, int *vals, int tam) {
    *ptr = (ArrayList*) malloc(sizeof(ArrayList));
    int cap = DEFAULT_CAP_SIZE;
    // Passou [] vazia
    if (tam == 0) {
        (*ptr)->arr = (int*) calloc(DEFAULT_CAP_SIZE, sizeof(int));
        (*ptr)->tam = 0;
        (*ptr)->cap = cap;
    } else {
        cap = tam*2;
        (*ptr)->arr = (int*) calloc(cap, sizeof(int));

        for (int i = 0; i < tam; i++) {
            (*ptr)->arr[i] = vals[i];
        }

        (*ptr)->tam = tam;
        (*ptr)->cap = cap;
    }
}

void adicionarElemento(ArrayList **ptr, int val, int pos) {
    if (pos > ((*ptr)->cap - 1)) {
        while (((*ptr)->cap - 1) >= pos) {
            (*ptr)->cap *= 2;
        }
    } else if (pos == (*ptr)->tam || pos == -1) {
        (*ptr)->arr[(*ptr)->tam] = val; 
    } else {
    }
}

int main() {
    ArrayList *ptrTest = NULL;
    int tst[] = {1}; 
    int tam = sizeof(tst)/sizeof(tst[0]);
    iniciarArrayList(&ptrTest, tst, tam);
    if (ptrTest == NULL) {
        printf("\nFodeu gurizada");
    } else {
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]);
        }
    }
}