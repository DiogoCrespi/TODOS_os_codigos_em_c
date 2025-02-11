#ifndef BUSCAR_INFO_B_MAIS_TREE_H
#define BUSCAR_INFO_B_MAIS_TREE_H
#include "../BTree.h"

// Função recursiva para buscar uma chave na árvore B+
void* buscarInfoBTreeRecursivo(pNohBTree nohAtual, void* chave, FuncaoComparacao pfc) {
    // Caso base 1: Nó atual é nulo (não encontrado ou árvore vazia)
    if (nohAtual == NULL) {
        return NULL;
    }

    // Itera sobre os pares chave-valor do nó atual
    pNoh atual = nohAtual->listaChavesValores->primeiro;
    pChaveValor pcvAnterior = NULL;

    while (atual != NULL) {
        pChaveValor pcv = (pChaveValor)atual->info;

        printf("Comparando chave %d com chave %d\n", *(int*)chave, *(int*)pcv->chave);

        // Caso 2: Chave encontrada no nó atual
        if (pfc(chave, pcv->chave) == 0) {
            return pcv->valor;
        }

        // Caso 3: Chave menor que a atual, deve buscar no filho apropriado
        if (pfc(chave, pcv->chave) < 0) {
            break;
        }

        // Caso 4: Atualiza o ponteiro para o par chave-valor anterior e avança
        pcvAnterior = pcv;
        atual = atual->prox;
    }

    // Caso 5: Nó atual é folha, e a chave não foi encontrada
    if (nohAtual->ehFolha) {
        return NULL;
    }

    // Caso 6: Nó interno, busca recursivamente no filho apropriado
    return buscarInfoBTreeRecursivo(
        (pcvAnterior == NULL) ? nohAtual->primeiroFilho : pcvAnterior->filhoMaior,
        chave, pfc
    );
}

// Função principal para buscar uma chave na árvore
void* buscarInfoBTree(pDBTree arvore, void* chave, FuncaoComparacao pfc) {
    // Caso base: Árvore ou raiz nula
    if (arvore == NULL || arvore->raiz == NULL) {
        printf("Árvore vazia ou raiz é NULL.\n");
        return NULL;
    }

    // Chama a função recursiva para realizar a busca
    return buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);
}

#endif //BUSCAR_INFO_B_MAIS_TREE_H
