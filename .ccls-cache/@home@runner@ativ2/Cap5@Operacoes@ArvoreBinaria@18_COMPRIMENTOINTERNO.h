#ifndef COMPRIMENTO_INTERNO_H
#define COMPRIMENTO_INTERNO_H

#include "../../ArvoreBinaria.h"

int comprimentoInternoRecursivo(pNohArvore noh, int profundidade) {
    if (noh == NULL)
        return 0;

    if (noh->esquerda == NULL && noh->direita == NULL)
        return profundidade;

    return comprimentoInternoRecursivo(noh->esquerda, profundidade + 1) +
           comprimentoInternoRecursivo(noh->direita, profundidade + 1);
}

int comprimentoInterno(pDArvore arvore) {
    if (arvore == NULL)
        return 0;

    return comprimentoInternoRecursivo(arvore->raiz, 0);
}

#endif
