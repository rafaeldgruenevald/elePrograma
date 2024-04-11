#include <stdio.h>

typedef struct pessoa {
    float altura;
    float peso;
    int idade;
    char nome[20];
} pessoa;

void dadosPessoa(pessoa *input) {
    printf("Qual o seu nome?\n");
    scanf("%s", input->nome);
    printf("Qual a sua idade?\n");
    scanf("%i", &input->idade);
    printf("Qual a seu peso?\n");
    scanf("%f", &input->peso);
    printf("Qual a sua altura?\n");
    scanf("%f", &input->altura);
}

int main() {
    pessoa pessoaTeste;
    dadosPessoa(&pessoaTeste);
    printf("%s, %d, %f, %f", pessoaTeste.nome, pessoaTeste.idade, pessoaTeste.altura, pessoaTeste.peso);
}