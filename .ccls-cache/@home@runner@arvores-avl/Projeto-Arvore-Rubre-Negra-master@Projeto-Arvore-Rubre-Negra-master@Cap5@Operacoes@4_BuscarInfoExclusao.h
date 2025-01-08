#ifndef BUSCAR_INFO_EXCLUSAO_H
#define BUSCAR_INFO_EXCLUSAO_H
#include "../ArvoreRubroNegra.h"

pNohArvore BuscarInfoRecursivoExclusao(pNohArvore raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela) {
    if (raiz == sentinela) {
        return sentinela;
    }

    int comparacao = pfc(info, raiz->info);

    if (comparacao == 0) {
        return raiz;
    } else if (comparacao < 0) {
        return BuscarInfoRecursivoExclusao(raiz->direita, info, pfc, sentinela);
    } else {
        return BuscarInfoRecursivoExclusao(raiz->esquerda, info, pfc, sentinela);
    }
}

pNohArvore BuscarInfoExclusao(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == arvore->sentinela) {
        return arvore->sentinela;
    }

    return BuscarInfoRecursivoExclusao(arvore->raiz, info, pfc, arvore->sentinela);
}

#endif // BUSCAR_INFO_EXCLUSAO_H
