#ifndef ESTRITAMENTE_BINARIA_H
#define ESTRITAMENTE_BINARIA_H
#include "../../ArvoreBinaria.h"

int estritamenteBinariaRecursivo(pNohArvore noh) {
    if (noh == NULL)
        return 1;

    if ((noh->esquerda == NULL && noh->direita != NULL) || (noh->esquerda != NULL && noh->direita == NULL))
        return 0;

    return estritamenteBinariaRecursivo(noh->esquerda) && estritamenteBinariaRecursivo(noh->direita);
}

int estritamenteBinaria(pDArvore arvore) {
    if (arvore == NULL)
        return 1;

    return estritamenteBinariaRecursivo(arvore->raiz);
}

#endif
