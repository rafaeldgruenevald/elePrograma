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
*  respeitando os parâmetros e tipos de dados definidos,
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

#define MAXMSG 100  //tamanho maximo mensagens

int main()
{
 // Variaveis
    char tabRestaUm[NLIN][NCOL]; // tabuleiro
    status_t estado=OK;         // resultado da função
    movimento_t jogada;         // movimento a realizar
    char msg[MAXMSG];           // mensagem para usuario
    unsigned int numJogadas=0;  // Numero de jogadas realizadas

// Inicializacao
    setlocale(LC_ALL,"");        // caracteres da lingua portuguesa
    inicTab(tabRestaUm);        // Preenche tabuleiro inicial
    showTab(tabRestaUm);        // Exibe o tabulero
// Laco principal
    do{
      estado=qualJogada(&jogada);
      if(estado!=DERROTA){ // Se não pedir para sair, segue o jogo
        estado=movimenta(tabRestaUm,&jogada);
        switch(estado)
        {
        case   INVALIDO:
                strncpy(msg,"Movimento inválido\n",MAXMSG);
                break;
        case    VAZIO:
                strncpy(msg,"Sem peças a mover\n",MAXMSG);
                break;
        case    OCUPADO:
              strncpy(msg,"Posição destino ocupada\n",MAXMSG);
                break;

        default:
            showTab(tabRestaUm);
            numJogadas++;
            estado=confereJogo(tabRestaUm);
            switch(estado)
            {
            case VITORIA:
                strncpy(msg,"Parabéns, sobrou só um !\n",MAXMSG);
                break;
            case DERROTA:
                strncpy(msg,"Acabaram as jogadas !\n",MAXMSG);
                break;
            default:
                strncpy(msg,"jogo continua...\n",MAXMSG);
            }
        }
        printf(msg);
     }// fim if derrota

    }while(estado!= VITORIA && estado!= DERROTA);

    printf("Fim de jogo com %d rodadas!\n",numJogadas);


}// fim main
