#ifndef BALANCEAR_ARVORE_H
#define BALANCEAR_ARVORE_H
#include "../ArvoreAVL.h"
#include <math.h>

pNohArvore balancearRecursivo(pNohArvore raiz) {
    if (raiz == NULL) {
        return NULL;
    }

    raiz->esquerda = balancearRecursivo(raiz->esquerda);
    raiz->direita = balancearRecursivo(raiz->direita);

    raiz->fb = alturaRecursiva(raiz->direita) - alturaRecursiva(raiz->esquerda);

    if (raiz->fb == 2) {
        if (raiz->direita->fb >= 0) {
            return rotacaoEsquerda(raiz);
        } else {
            return rotacaoDireitaEsquerda(raiz);
        }
    }

    if (raiz->fb == -2) {
        if (raiz->esquerda->fb <= 0) {
            return rotacaoDireita(raiz);
        } else {
            return rotacaoEsquerdaDireita(raiz);
        }
    }

    return raiz;
}

void balancear(pDArvore arvore) {
    if (arvore == NULL) {
        return;
    }

    arvore->raiz = balancearRecursivo(arvore->raiz);
}

#endif
