#ifndef BUSCAR_INFO_EXCLUSAO_RUBRO_H
#define BUSCAR_INFO_EXCLUSAO_RUBRO_H
#include "../ArvoreRubroNegra.h"

pNohArvore buscarInfoRecursivoExclusao(pNohArvore raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela)
{
    if (raiz == sentinela) {
        return sentinela;
    }

    int comparacao = pfc(info, raiz->info);

    if (comparacao == 0) {
        return raiz;
    } else if (comparacao < 0) {
        pNohArvore nodoDireito = buscarInfoRecursivoExclusao(raiz->direita, info, pfc, sentinela);
        if (nodoDireito != sentinela) {
            return nodoDireito;
        }
    } else {
        pNohArvore nodoEsquerdo = buscarInfoRecursivoExclusao(raiz->esquerda, info, pfc, sentinela);
        if (nodoEsquerdo != sentinela) {
            return nodoEsquerdo;
        }
    }

    return sentinela;
}

pNohArvore buscarInfoExclusao(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore == NULL || arvore->raiz == arvore->sentinela) {
        return arvore->sentinela;
    }

    return buscarInfoRecursivoExclusao(arvore->raiz, info, pfc, arvore->sentinela);
}


#endif 
