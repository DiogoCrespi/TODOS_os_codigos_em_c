#ifndef POSORDEM_ARVORE_BINARIA_H
#define POSORDEM_ARVORE_BINARIA_H
#include "../../ArvoreBinaria.h"

void posOrdemRecursivo(pNohArvore noh, FuncaoImpressao fi) {
    if (noh == NULL)
        return;

    posOrdemRecursivo(noh->esquerda, fi);
    posOrdemRecursivo(noh->direita, fi);
    fi(noh->info);
}

void posOrdem(pDArvore arvore, FuncaoImpressao fi) {
    if (arvore == NULL || arvore->raiz == NULL)
        return;

    posOrdemRecursivo(arvore->raiz, fi);
}

#endif

