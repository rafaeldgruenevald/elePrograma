/**********************************************************
 * @brief    Trabalho trimestral - Resta Um
 * @author   Marcos Zuccolotto
 * @date     abr/2024
 * @version  1.0
 *
 * Fundacao Liberato - Curso de Eletronica
 * Elementos de programacao  - prof. Marcos Zuccolotto
 *
 * Trabalho trimestral - Struct / enum / ponteiros
 *
 * Implemente as funcoes abaixo comforme especificacao,
 *  respeitando os par�metros e tipos de dados definidos,
 *  seguindo as orientacoes dadas
 * - qualJogada()
 * - movimenta()
 * - confereJogo()
 *
 * Equipe : Bancada (2 alunos)
 *
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "resta_um.h"

#define MAXMSG 100 // tamanho maximo mensagens

int main()
{
    // Variaveis
    char tabRestaUm[NLIN][NCOL]; // tabuleiro
    status_t estado = OK;        // resultado da fun��o
    movimento_t jogada;          // movimento a realizar
    char msg[MAXMSG];            // mensagem para usuario
    unsigned int numJogadas = 0; // Numero de jogadas realizadas

    // Inicializacao
    setlocale(LC_ALL, ""); // caracteres da lingua portuguesa
    inicTab(tabRestaUm);   // Preenche tabuleiro inicial
    showTab(tabRestaUm);   // Exibe o tabulero
                           // Laco principal
    do
    {
        estado = qualJogada(&jogada);
        if (estado != DERROTA)
        { // Se n�o pedir para sair, segue o jogo
            estado = movimenta(tabRestaUm, &jogada);
            switch (estado)
            {
            case INVALIDO:
                strncpy(msg, "Movimento inv�lido\n", MAXMSG);
                break;
            case VAZIO:
                strncpy(msg, "Sem pe�as a mover\n", MAXMSG);
                break;
            case OCUPADO:
                strncpy(msg, "Posi��o destino ocupada\n", MAXMSG);
                break;

            default:
                showTab(tabRestaUm);
                numJogadas++;
                estado = confereJogo(tabRestaUm);
                switch (estado)
                {
                case VITORIA:
                    strncpy(msg, "Parab�ns, sobrou s� um !\n", MAXMSG);
                    break;
                case DERROTA:
                    strncpy(msg, "Acabaram as jogadas !\n", MAXMSG);
                    break;
                default:
                    strncpy(msg, "jogo continua...\n", MAXMSG);
                }
            }
            printf(msg);
        } // fim if derrota

    } while (estado != VITORIA && estado != DERROTA);

    printf("Fim de jogo com %d rodadas!\n", numJogadas);

} // fim main

status_t qualJogada(movimento_t *jog)
{
    char input;
    while (input != 's' && input != 'S' && input != 'n' && input != 'N')
    {
        printf("\nDeseja continuar jogando? (S)im ou (N)ao");
        scanf(" %c", &input);
    }
    if (input == 's' || input == 'S')
    {
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

        printf("Coluna de Origem: %i, Linha de Origem: %i, Coluna de Destino: %i, Linha de Destino: %i\n", jog->origem.col, jog->origem.lin, jog->destino.col, jog->destino.lin);
        return OK;
    }
    else
    {
        return DERROTA;
    }
}

status_t movimenta(char *tab, movimento_t *jog)
{
    int diffLin, diffCol;
    char sitOrigem, sitDestino;

    diffLin = jog->origem.lin - jog->destino.lin;
    diffCol = jog->origem.col - jog->destino.col;
    sitOrigem = *(tab + jog->origem.lin * NCOL + jog->origem.col);
    sitDestino = *(tab + jog->destino.lin * NCOL + jog->destino.col);
    printf("%c %c\n", sitOrigem, sitDestino);

    if (jog->origem.lin >= NLIN || jog->destino.lin >= NLIN || jog->origem.col >= NCOL || jog->destino.col >= NCOL)
    {
        return INVALIDO;
    }
    if ((diffLin != 0 && diffCol != 0) || (abs(diffLin) != 2 && abs(diffCol) != 2))
    {
        return INVALIDO;
    }

    if (sitDestino == VZ && sitOrigem == OC)
    {
        if (diffLin == 0)
        {
            if (diffCol == 2 && *(tab + jog->origem.lin * NCOL + jog->origem.col - 1) == OC)
            {
                *(tab + jog->origem.lin * NCOL + jog->origem.col - 1) = VZ;
            }
            else if (diffCol == -2 && *(tab + jog->origem.lin * NCOL + jog->origem.col + 1) == OC)
            {
                *(tab + jog->origem.lin * NCOL + jog->origem.col + 1) = VZ;
            }
            else
            {
                return INVALIDO;
            }
        }
        else if (diffCol == 0)
        {
            if (diffLin == 2 && *(tab + (jog->origem.lin - 1) * NCOL + jog->origem.col) == OC)
            {
                *(tab + (jog->origem.lin - 1) * NCOL + jog->origem.col) = VZ;
            }
            else if (diffLin == -2 && *(tab + (jog->origem.lin + 1) * NCOL + jog->origem.col) == OC)
            {
                *(tab + (jog->origem.lin + 1) * NCOL + jog->origem.col) = VZ;
            }
            else
            {
                return INVALIDO;
            }
        }
        else
        {
            return INVALIDO;
        }

        *(tab + jog->origem.lin * NCOL + jog->origem.col) = VZ;
        *(tab + jog->destino.lin * NCOL + jog->destino.col) = OC;
        return OK;
    }
    else if (sitOrigem == VZ)
    {
        return VAZIO;
    }
    else if (sitDestino == OC)
    {
        return OCUPADO;
    }
    else
    {
        return INVALIDO;
    }
}

status_t confereJogo(char *tab)
{
    int pecas = 0;
    int movimentosPossiveis = 0;

    for (int i = 0; i < NLIN; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            char *pos = tab + (i * NCOL) + j;
            if (*pos == OC)
            {
                pecas++;
                if (i > 1 && *(tab + ((i - 1) * NCOL) + j) == OC && *(tab + ((i - 2) * NCOL) + j) == VZ)
                    movimentosPossiveis++;
                if (i < NLIN - 2 && *(tab + ((i + 1) * NCOL) + j) == OC && *(tab + ((i + 2) * NCOL) + j) == VZ)
                    movimentosPossiveis++;
                if (j > 1 && *(tab + (i * NCOL) + (j - 1)) == OC && *(tab + (i * NCOL) + (j - 2)) == VZ)
                    movimentosPossiveis++;
                if (j < NCOL - 2 && *(tab + (i * NCOL) + (j + 1)) == OC && *(tab + (i * NCOL) + (j + 2)) == VZ)
                    movimentosPossiveis++;
            }
        }
    }

    if (pecas == 1)
    {
        return VITORIA;
    }
    else if (movimentosPossiveis == 0)
    {
        return DERROTA;
    }
    else
    {
        return OK;
    }
}