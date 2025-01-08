#ifndef DESENHA_ARVORE_NIVELADA_H
#define DESENHA_ARVORE_NIVELADA_H

#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

#define ESPACO 5

void desenhaNivel(pNohBTree raiz, int nivel, FuncaoImpressao fi) {
    if (raiz == NULL) {
        return;
    }

    // Imprime o n� atual com indenta�o
    for (int i = 0; i < nivel * ESPACO; i++) {
        printf(" ");
    }
    printf("[ ");
    for (int i = 0; i < raiz->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i + 1);
        fi(pcv->chave);
        if (i < raiz->listaChavesValores->quantidade - 1) {
            printf(", ");
        }
    }
    printf(" ]");

    // Verifica se h� filhos e inicia uma nova linha
    if (!ehFolha(raiz)) {
        printf("\n");
        pNohBTree atual = raiz->primeiroFilho;
        for (int i = 0; i <= raiz->listaChavesValores->quantidade; i++) {
            desenhaNivel(atual, nivel + 1, fi);
            if (atual && i < raiz->listaChavesValores->quantidade) {
                pChaveValor pcv = buscarInfoPos(raiz->listaChavesValores, i + 1);
                atual = pcv->filhoMaior;
            }
        }
    } else {
        printf("\n");
    }
}

void desenhaArvoreNivelada(pDBTree arvore, FuncaoImpressao fi) {
    if (arvore->raiz == NULL) {
        printf("[ ]\n");
        return;
    }
    desenhaNivel(arvore->raiz, 0, fi);  // Come�a no n�vel 0
}

#endif
