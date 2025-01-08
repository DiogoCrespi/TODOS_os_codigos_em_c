#ifndef BUSCAR_INFO_B_MAIS_TREE_H
#define BUSCAR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

pNohBTree buscarInfoBTreeRecursivo(pNohBTree raiz, void *chave, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        return NULL;
    }

    if (ehFolha(raiz)) {
        int i = 1;
        while (i <= raiz->listaChavesValores->quantidade) {
            pChaveValor pcv = (pChaveValor) buscarInfoPos(raiz->listaChavesValores, i);
            int resultado = pfc(pcv->chave, chave);

            if (resultado == 0) {
                return pcv->filhoMaior;
            }
            i++;
        }
        return NULL;
    }

    int i = 1;
    while (i <= raiz->listaChavesValores->quantidade) {
        pChaveValor pcv = (pChaveValor) buscarInfoPos(raiz->listaChavesValores, i);
        int resultado = pfc(pcv->chave, chave);

        if (resultado == 0) {
            return pcv->filhoMaior;
        } else if (resultado > 0) {
            return buscarInfoBTreeRecursivo(pcv->filhoMaior, chave, pfc);
        }
        i++;
    }

    return NULL;
}

void* buscarInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
    pNohBTree noh = buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);
    if (noh != NULL) {
        return noh->listaChavesValores; 
    }
    return NULL;
}

#endif
