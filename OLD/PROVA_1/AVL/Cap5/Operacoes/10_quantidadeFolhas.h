#ifndef QTDEFOLHAS_ARVORE_BINARIA_H
#define QTDEFOLHAS_ARVORE_BINARIA_H
#include "../ArvoreAVL.h"

int quantidadeFolhasRecursiva(pNohArvore raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }

    return quantidadeFolhasRecursiva(raiz->esquerda) + quantidadeFolhasRecursiva(raiz->direita);
}

int quantidadeFolhas(pDArvore arvore) {
    if (arvore == NULL) {
        return 0;
    }

    return quantidadeFolhasRecursiva(arvore->raiz);
}

#endif




