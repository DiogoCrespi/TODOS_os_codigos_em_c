#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H

#include "../../ArvoreBinaria.h"

pNohArvore obterMinimo(pNohArvore noh) {
    while (noh->esquerda != NULL) {
        noh = noh->esquerda;
    }
    return noh;
}

pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        return NULL;
    }

    int comp = pfc(raiz->info, info);

    // Caso 1
    if (comp == 0 && raiz->esquerda == NULL && raiz->direita == NULL) {
        free(raiz->info);
        free(raiz);
        return NULL;
    }

    // Caso 2
    if (comp == 0) {
        pNohArvore temp;
        if (raiz->esquerda == NULL) {
            temp = raiz->direita;
        } else {
            temp = raiz->esquerda;
        }
        free(raiz->info);
        free(raiz);
        return temp;
    }

    // Caso 3
    if (comp == 0 && raiz->esquerda != NULL && raiz->direita != NULL) {
        pNohArvore temp = obterMinimo(raiz->direita);
        raiz->info = temp->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, pfc);
        return raiz;
    }

    // Caso recursivo
    if (comp < 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, pfc);
    } else {
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, pfc);
    }

    return raiz;
}

int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore->raiz == NULL) {
        return 0;
    }

    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 1;
}

#endif
