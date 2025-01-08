#ifndef NOMINIMO_H
#define NOMINIMO_H
#include "../ArvoreRubroNegra.h"

pNohArvore NoMinimo(pNohArvore raiz, pNohArvore sentinela) {
    if (raiz == sentinela)
        return sentinela;

    pNohArvore aux = raiz;

    while (aux->esquerda != sentinela)
        aux = aux->esquerda;

    return aux;
}

#endif
