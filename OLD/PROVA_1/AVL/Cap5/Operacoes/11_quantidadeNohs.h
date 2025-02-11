#ifndef QTDENOHS_ARVORE_BINARIA_H
#define QTDENOHS_ARVORE_BINARIA_H
#include "../ArvoreAVL.h"

int quantidadeNohsRecursiva(pNohArvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + quantidadeNohsRecursiva(raiz->esquerda) + quantidadeNohsRecursiva(raiz->direita);
}

int quantidadeNohs(pDArvore arvore) {
    if (arvore == NULL) {
        return 0;
    }

    return quantidadeNohsRecursiva(arvore->raiz);
}

#endif




