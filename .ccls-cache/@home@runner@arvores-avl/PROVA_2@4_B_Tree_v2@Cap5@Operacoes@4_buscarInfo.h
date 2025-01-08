#ifndef BUSCAR_INFO_BTREE_H
#define BUSCAR_INFO_BTREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

// Função de busca binária modificada para percorrer uma lista encadeada
int busca_binaria(pNohBTree no, void *chave, FuncaoComparacao pfc) {
    int i = 0, f = no->listaChavesValores->quantidade - 1;
    int meio;

    while (i <= f) {
        meio = (i + f) / 2;
        pChaveValor pcv = (pChaveValor) buscarInfoPos(no->listaChavesValores, meio);

        int cmp = pfc(pcv->chave, chave);
        if (cmp == 0) {
            return meio; // Chave encontrada
        } else if (cmp > 0) {
            f = meio - 1; // Procura à esquerda
        } else {
            i = meio + 1; // Procura à direita
        }
    }

    return i; // Retorna a posição onde a chave deveria estar
}

// Função que busca a posição de um elemento na lista, dado um índice
void* buscarInfoPosb(pDLista lista, int pos) {
    pNoh atual = lista->primeiro;
    int i = 0;
    while (atual != NULL && i < pos) {
        atual = atual->prox;
        i++;
    }
    return (atual != NULL) ? atual->info : NULL;
}

// Função recursiva de busca na árvore B
pNohBTree buscarInfoBTreeRecursivo(pNohBTree raiz, void *chave, FuncaoComparacao pfc) {
    if (raiz == NULL) {
        return NULL; // Nó vazio, chave não encontrada
    }

    // Realiza a busca binária dentro do nó
    int pos = busca_binaria(raiz, chave, pfc);

    // Verifica se a chave foi encontrada no nó
    pChaveValor pcv = (pChaveValor) buscarInfoPos(raiz->listaChavesValores, pos);
    if (pcv != NULL && pfc(pcv->chave, chave) == 0) {
        // Chave encontrada, retorna o valor ou o nó
        return raiz;
    }

    // Se a chave não foi encontrada, busca recursivamente no filho apropriado
    if (raiz->primeiroFilho == NULL) {
        return NULL; // É uma folha e a chave não foi encontrada
    }

    // Se a chave não foi encontrada, segue a busca recursiva no filho
    pChaveValor pcvFilho = (pChaveValor) buscarInfoPos(raiz->listaChavesValores, pos);
    return buscarInfoBTreeRecursivo(pcvFilho->filhoMaior, chave, pfc);
}

/* ----------------------------------------------------------*/
// Função principal de busca na árvore B
void* buscarInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc) {
    pNohBTree resultado = buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);
    if (resultado == NULL) {
        return NULL; // Chave não encontrada
    }

    // Caso a chave tenha sido encontrada, retorna o valor associado
    int pos = busca_binaria(resultado, chave, pfc);
    if (pos < resultado->listaChavesValores->quantidade &&
        pfc(((pChaveValor)buscarInfoPos(resultado->listaChavesValores, pos))->chave, chave) == 0) {
        return ((pChaveValor)buscarInfoPos(resultado->listaChavesValores, pos))->valor;
    }

    return NULL; // Em caso de erro, não deveria chegar aqui
}

#endif
