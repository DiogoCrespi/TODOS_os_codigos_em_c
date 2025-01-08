#ifndef ESPELHAR_ARVORE_H
#define ESPELHAR_ARVORE_H
#include "../../ArvoreBinaria.h"

void espelhoRecursivo(pNohArvore noh) {
    if (noh == NULL)
        return;

    pNohArvore temp = noh->esquerda;
    noh->esquerda = noh->direita;
    noh->direita = temp;

    espelhoRecursivo(noh->esquerda);
    espelhoRecursivo(noh->direita);
}

void espelho(pDArvore arvore) {
    if (arvore == NULL)
        return;

    espelhoRecursivo(arvore->raiz);
}

#endif
