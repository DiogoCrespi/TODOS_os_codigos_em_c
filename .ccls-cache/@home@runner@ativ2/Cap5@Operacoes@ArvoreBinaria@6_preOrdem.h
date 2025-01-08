#ifndef PREORDEM_ARVORE_BINARIA_H
#define PREORDEM_ARVORE_BINARIA_H

#include "../../ArvoreBinaria.h"

void preOrdemRecursivo(pNohArvore noh, FuncaoImpressao fi) {
    if (noh == NULL)
        return;

    fi(noh->info);
    preOrdemRecursivo(noh->esquerda, fi);
    preOrdemRecursivo(noh->direita, fi);
}

void preOrdem(pDArvore arvore, FuncaoImpressao fi) {
    if (arvore == NULL || arvore->raiz == NULL)
        return;

    preOrdemRecursivo(arvore->raiz, fi);
}

#endif
