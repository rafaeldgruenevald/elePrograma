/**********************************************************
* @file     restaUm.h
* @brief    Resta Um - defines, tipos dados e prototipos
* @author   Rafael Cunha, Rafael Delazeri
* @date     abr/2024
* @version  1.1
**********************************************************/
#ifndef _RESTA_UM_H_   // Declaracao de guarda
#define _RESTA_UM_H_

// Dimensoes da matriz que guarda o tabuleiro
#define NCOL 7
#define NLIN 7

// Marcadores do tabuleiro
#define  NU ' '  // Ponto invalido/proibido
#define  OC '*'  // Ponto ocupado
#define  VZ '_'  // Ponto livre/vazio

/* Tipos de dados */
// Posicao da peca no tabuleiro

typedef struct {
    int lin; // Posicao linha
    int col; // Posicao destino
} posTab_t;

// Movimento a ser realizado
typedef struct {
    posTab_t origem;   // Posicao inicio/origem
    posTab_t destino; // Posicao fim
} movimento_t;

typedef enum {
    OK = 0,   // 0 - movimento executado, segue o jogo
    INVALIDO, // 1 - n�o existe peca a pular sobre/retira/fora tabuleiro/movimento longo, curto ou em diagonal
    OCUPADO,  // 2 - posicao destino ocupada
    VAZIO,    // 3 - posicao origem vazia
    VITORIA,  // 4 - vitoria - fim jogo
    DERROTA   // 5 - nao tem mais o que fazer
} status_t;

/* Prototipos */
/*
* @brief  Inicializa tabuleiro
* @param  tabuleiro
* @retval none
*/

void inicTab(char tab[][7]) {
    for (int i = 0; i < NLIN; i++) {
        for (int j = 0; j < NCOL; j++) {
            tab[i][j] = OC;
            if (i == 0 || i == 1 || i == 5 || i == 6) {
                if (j == 0 || j == 1 || j == 5 || j == 6) {
                    tab[i][j] = NU;
                }
            }
        }
    }
    tab[3][3] = VZ;
}

/*
* @brief  Exibe o tabuleiro
* @param  tabuleiro
* @retval none
*/
void showTab(char tab[][7]) {
    printf("  0 1 2 3 4 5 6");
    printf("\n");
    for (int i = 0; i < NLIN; i++) {
        printf("%i ", i);
        for (int j = 0; j < NCOL; j++) {
            printf("%c ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/**
* @brief  Entrada dados da jogada
* @param  movimentacao a realizar
* @retval OK - jogador definiu a movimentacao
          DERROTA - jogador desistiu do jogo
*/
status_t qualJogada(movimento_t* jog) {
    char input;
    while (input != 's' && input != 'S' && input != 'n' && input != 'N') {
        printf("\nDeseja continuar jogando? (S)im ou (N)ao");
        scanf(" %c", &input);
    } 
    if (input == 's' || input == 'S') {
        printf("\nInsira as coordenadas da peça que você deseja mover:");
        printf("\nColuna de Origem:");
        scanf("%i", &(jog->origem.col));
        printf("\nLinha de Origem:");
        scanf("%i", &(jog->origem.lin));

        printf("\nInsira as coordenadas para onde você quer ir:");
        printf("\nColuna de Destino:");
        scanf("%i", &(jog->destino.col));
        printf("\nLinha de Destino:");
        scanf("%i", &(jog->destino.lin));

        printf("Coluna de Origem: %i, Linha de Origem: %i, Coluna de Destino: %i, Linha de Destino: %i", jog->origem.col, jog->origem.lin, jog->destino.col, jog->destino.lin);
        return OK;
    } else {
        return DERROTA;
    }
}

/*
* @brief  Executa a movimentacao solicitada
* @param  tabuleiro
* @param  movimentacao a realizar
* @retval OK - movimento executado, segue o jogo
          INVALIDO - movimento invalido
          OCUPADO - posicao destino ocupada
          VAZIO - posicao origem vazia
*/
status_t movimenta(char tab[][7], movimento_t* jog) {}

/*
* @brief  Confere possibilidades de continuacao
* @param  tabuleiro
* @retval OK - segue o jogo
          VITORIA - restou um, acabou
          DERROTA - nada mais a fazer, fim de jogo
*/
status_t confereJogo(char tab[][7]) {}

#endif //_RESTA_UM_H_
