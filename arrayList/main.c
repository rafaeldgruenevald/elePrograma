#include <stdlib.h>
#include <stdio.h>

#define CAPACIDADE_PADRAO 10
#define FATOR_DE_MULTIPLICIDADE 2

typedef struct ArrayList {
    int *arr;
    int tam;
    int cap;
} ArrayList;

void iniciarArrayList(ArrayList **ptr, int *vals, int tam) {
    *ptr = (ArrayList*) malloc(sizeof(ArrayList));
    // Passou [] vazia
    if (tam == 0) {
        (*ptr)->arr = (int*) calloc(CAPACIDADE_PADRAO, sizeof(int));
        (*ptr)->tam = 0;
        (*ptr)->cap = CAPACIDADE_PADRAO;
    } else {
        int cap = tam*2;
        (*ptr)->arr = (int*) calloc(cap, sizeof(int));

        for (int i = 0; i < tam; i++) {
            (*ptr)->arr[i] = vals[i];
        }

        (*ptr)->tam = tam;
        (*ptr)->cap = cap;
    }
}


int adicionarElemento(ArrayList **ptr, int val, int pos) {
    (*ptr)->tam += 1;

    // Caso posição > tamanho, definir a posição como o tamanho
    if (pos > (*ptr)->tam) {
      (*ptr)->tam = pos + 1;
    }

    // Checa se pos > cap, caso correto dobra tamanho da Array ate ser suficiente
    while (pos > (*ptr)->cap) {
      (*ptr)->cap *= FATOR_DE_MULTIPLICIDADE;
    }

    // Checa se tamanho == capacidade, caso correto dobra tamanho da Array
    if ((*ptr)->tam >= (*ptr)->cap) {
	(*ptr)->cap *= FATOR_DE_MULTIPLICIDADE;
    }

    int *tempArray = (int*) calloc((*ptr)->cap, sizeof(int));

    // Adicionar no começo da Array
    if (pos == 0) {
	tempArray[0] = val;
	for (int i = 1; i < (*ptr)->tam; i++) {
	    tempArray[i] = (*ptr)->arr[i - 1];
	}
	free((*ptr)->arr);
	(*ptr)->arr = tempArray;
	return 1;
    }

    if (pos < 0) {
      pos = ((*ptr)->tam - 1);
    }

    // Adicionar depois do ultimo elemento da Array
    if (pos == ((*ptr)->tam - 1)) {
	tempArray[pos] = val;
	for (int i = 0; i < ((*ptr)->tam - 1); i++) {
	    tempArray[i] = (*ptr)->arr[i];
	}
	free((*ptr)->arr);
	(*ptr)->arr = tempArray;
	(*ptr)->tam = pos + 1;
	return 1;
    }

    // Adicionar no meio
    for (int i = 0; i < ((*ptr)->tam - 1); i++) {
	if (i < pos || i > pos) {
	    tempArray[i] = (*ptr)->arr[i];
	} else {
	    tempArray[i] = val;
	}
    }
    (*ptr)->tam -= 1;
    free((*ptr)->arr);
    (*ptr)->arr = tempArray;
    return 1;
}

int modificarElemento(ArrayList **ptr, int val, int pos) {
    if (pos > (*ptr)->cap || pos < 0) {
	return -1;
    }
    (*ptr)->arr[pos] = val;
    return 1;
}

int removerElemento(ArrayList **ptr, int pos) {
    // Caso pos invalida
    if (pos > (*ptr)->cap) {
	return -1;
    }

    (*ptr)->tam -= 1;

    // Remover Elemento do começo da Array
    if (pos == 0) {
	for (int i = 1; i <= (*ptr)->tam; i++) {
	    (*ptr)->arr[i - 1] = (*ptr)->arr[i];
	}
	return 1;
    }

    // Remover Elemento do final da Array
    if (pos == ((*ptr)->tam - 1) || pos < 0) {
        (*ptr)->arr[(*ptr)->tam] = 0;
	return 1; 
    }

    // Guardando elementos que vem depois da pos
    for (int i = pos; i < (*ptr)->tam; i++) {
	(*ptr)->arr[i] = (*ptr)->arr[i + 1];
    }
    return 1;
}

int trimArrayList(ArrayList **ptr) {
    // O tamanho da Array e sua capacidade são iguais, nada a fazer
    if ((*ptr)->tam == (*ptr)->cap) {
	return 1;
    }
    (*ptr)->cap = (*ptr)->tam;
    int *tempArray = (int*) calloc((*ptr)->cap, sizeof(int));
    for (int i = 0; i < (*ptr)->tam; i++) {
        tempArray[i] = (*ptr)->arr[i]; 
    }
    free((*ptr)->arr);
    (*ptr)->arr = tempArray;
    return 1;
}

int main() {
    ArrayList *ptrTest = NULL;
    int tst[] = {}; 
    int tam = sizeof(tst)/sizeof(tst[0]);
    iniciarArrayList(&ptrTest, tst, tam);
    if (ptrTest == NULL) {
        printf("\nFodeu gurizada");
    } else {
        printf("\nTam = %d",ptrTest->tam);
        printf("\nFunfando");
        printf("\nCap = %d",ptrTest->cap);
        printf("\nFunfando");
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]); 
	} 
	adicionarElemento(&ptrTest, 60, 20); 
        printf("\nTam = %d",ptrTest->tam);
        printf("\nCap = %d",ptrTest->cap);
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]);
        }
	adicionarElemento(&ptrTest, 70, 19); 
        printf("\nTam = %d",ptrTest->tam);
        printf("\nCap = %d",ptrTest->cap);
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]);
        }
	adicionarElemento(&ptrTest, 80, 0); 
        printf("\nFunfando");
	adicionarElemento(&ptrTest, 80, -1); 
        printf("\nFunfando");
	adicionarElemento(&ptrTest, 80, -1); 
        printf("\nFunfando");
	adicionarElemento(&ptrTest, 80, -1); 
        printf("\nFunfando");
	trimArrayList(&ptrTest);
        printf("\nTam = %d",ptrTest->tam);
        printf("\nCap = %d",ptrTest->cap);
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]);
        }
	adicionarElemento(&ptrTest, 90, 4); 
	adicionarElemento(&ptrTest, 90, 3); 
	adicionarElemento(&ptrTest, 90, 2); 
	adicionarElemento(&ptrTest, 90, 1); 
	adicionarElemento(&ptrTest, 80, -1); 
        printf("\nTam = %d",ptrTest->tam);
        printf("\nCap = %d",ptrTest->cap);
        for (int i = 0; i < ptrTest->tam; i++) {
            printf("\nPos %d = %d", i, ptrTest->arr[i]);
        }
    }
}
