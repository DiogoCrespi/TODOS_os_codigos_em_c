
#ifndef EXCLUIR_INFO_B_MAIS_TREE_H
#define EXCLUIR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

// Função recursiva para excluir uma chave da árvore B+
pNohBTree excluirInfoBTreeRecursivo(pNohBTree nohAtual, void* chave, FuncaoComparacao pfc) {
    if (nohAtual == NULL) {
        return NULL;
    }

    pNoh atual = nohAtual->listaChavesValores->primeiro;
    pChaveValor anterior = NULL;

    while (atual != NULL) {
        pChaveValor pcv = (pChaveValor)atual->info;
        if (pfc(chave, pcv->chave) == 0) {
            if (nohAtual->ehFolha) {
                excluirInfo(nohAtual->listaChavesValores, pcv, comparaChaveValor);
            } else {
                pChaveValor sucessor = (pChaveValor)buscarInfoPos(nohAtual->listaChavesValores, 2);
                if (sucessor != NULL) {
                    pcv->chave = sucessor->chave;
                    pcv->valor = sucessor->valor;
                    excluirInfo(nohAtual->listaChavesValores, sucessor, comparaChaveValor);
                }
            }
            break;
        }
        if (pfc(chave, pcv->chave) < 0) {
            break;
        }
        anterior = pcv;
        atual = atual->prox;
    }

    if (!nohAtual->ehFolha) {
        pNohBTree filho = (anterior == NULL) ? nohAtual->primeiroFilho : anterior->filhoMaior;
        excluirInfoBTreeRecursivo(filho, chave, pfc);

        if (nohAtual->listaChavesValores->quantidade < 1) {
            if (nohAtual->pai != NULL) {
                pNohBTree pai = nohAtual->pai;
                // Ajustar redistribuição ou fusão aqui
            }
        }
    }

    return nohAtual;
}

int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return 0;
    }
    arvore->raiz = excluirInfoBTreeRecursivo(arvore->raiz, chave, pfc);
    return 1;
}

#endif
