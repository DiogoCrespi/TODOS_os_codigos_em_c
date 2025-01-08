#ifndef BUSCAR_INFO_H
#define BUSCAR_INFO_H
#include "../ArvoreRubroNegra.h"

pNohArvore BuscarInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela) {
    if (raiz == sentinela) {
        return sentinela;
    }

    int comparacao = pfc(info, raiz->info);

    if (comparacao == 0) {
        return raiz;
    } else if (comparacao < 0) {
        return BuscarInfoRecursivo(raiz->direita, info, pfc, sentinela);
    } else {
        return BuscarInfoRecursivo(raiz->esquerda, info, pfc, sentinela);
    }
}

pNohArvore BuscarInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == arvore->sentinela) {
        return arvore->sentinela;
    }

    return BuscarInfoRecursivo(arvore->raiz, info, pfc, arvore->sentinela);
}

#endif
