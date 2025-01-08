#ifndef BALANCEADA_H
#define BALANCEADA_H

#include "../../ArvoreBinaria.h"

int alturaBalanceadaRecursiva(pNohArvore noh, char *balanceado) {
    if (noh == NULL) {
        return 0;
    }

    int alturaEsquerda = alturaBalanceadaRecursiva(noh->esquerda, balanceado);
    int alturaDireita = alturaBalanceadaRecursiva(noh->direita, balanceado);

    if (abs(alturaEsquerda - alturaDireita) > 1) {
        *balanceado = 0;
    }

    return (alturaEsquerda > alturaDireita ? alturaEsquerda : alturaDireita) + 1;
}

char balanceada(pDArvore arvore) {
    char balanceado = 1;
    if (arvore == NULL) {
        return 1;
    }

    alturaBalanceadaRecursiva(arvore->raiz, &balanceado);
    return balanceado;
}

#endif
