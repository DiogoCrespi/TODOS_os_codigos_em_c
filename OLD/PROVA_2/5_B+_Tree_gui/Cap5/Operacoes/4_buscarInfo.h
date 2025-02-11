#ifndef BUSCAR_INFO_B_MAIS_TREE_H
#define BUSCAR_INFO_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

// Função recursiva para buscar informação na árvore B+
void* buscarInfoBTreeRecursivo(pNohBTree nohAtual, void* chave, FuncaoComparacao pfc) {
    if (nohAtual == NULL) {
        printf("Nó atual é NULL.\n");
        return NULL;
    }

    pNoh atual = nohAtual->listaChavesValores->primeiro;
    pChaveValor pcvAnterior = NULL;

    while (atual != NULL) {
        pChaveValor pcv = (pChaveValor)atual->info;

        printf("Comparando chave %d com chave %d\n", *(int*)chave, *(int*)pcv->chave);

        if (pfc(chave, pcv->chave) == 0) {
            return pcv->valor;  // Chave encontrada, retorna o valor associado
        }

        if (pfc(chave, pcv->chave) < 0) {
            break;  // A chave buscada é menor que a chave atual
        }

        pcvAnterior = pcv;
        atual = atual->prox;
    }

    if (nohAtual->ehFolha) {
        return NULL;  // Se é uma folha e a chave não foi encontrada, retorna NULL
    }

    // Chama recursivamente para o nó filho apropriado
    return buscarInfoBTreeRecursivo(
        (pcvAnterior == NULL) ? nohAtual->primeiroFilho : pcvAnterior->filhoMaior,
        chave, pfc
    );
}

// Função principal para buscar na árvore B+
void* buscarInfoBTree(pDBTree arvore, void* chave, FuncaoComparacao pfc) {
    if (arvore == NULL || arvore->raiz == NULL) {
        printf("Árvore vazia ou raiz é NULL.\n");
        return NULL;
    }

    return buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);
}

#endif
