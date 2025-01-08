#ifndef POSORDEM_ARVORE_BINARIA_H
#define POSORDEM_ARVORE_BINARIA_H
#include "../ArvoreAVL.h"

void posOrdem(pNohArvore raiz, FuncaoImpressao fi) {
    if (raiz == NULL) {
        return;
    }

    posOrdem(raiz->esquerda, fi);
    posOrdem(raiz->direita, fi);
    fi(raiz->info);
}

#endif





