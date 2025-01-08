#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H
#include "../ArvoreAVL.h"

pNohArvore buscarInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        return NULL;
    }

    int resultado = pfc(raiz->info, info);
    if (resultado == 0) {
        return raiz;
    } else if (resultado < 0) {
        return buscarInfoRecursivo(raiz->esquerda, info, pfc);
    } else {
        return buscarInfoRecursivo(raiz->direita, info, pfc);
    }
}

pNohArvore buscarInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL) {
        return NULL;
    }

    return buscarInfoRecursivo(arvore->raiz, info, pfc);
}

#endif

