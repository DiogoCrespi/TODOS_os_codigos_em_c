#ifndef DESENHA_ARVORE_B_MAIS_TREE_H
#define DESENHA_ARVORE_B_MAIS_TREE_H
#include "../BTree.h"

void desenhaArvoreBMaisRecursivo(pNohBTree noh, int nivel, FuncaoImpressao impressao) {
    if (!noh) return;
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("[ ");
    for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
        impressao(pcv->chave);
        if (i < noh->listaChavesValores->quantidade) printf(" - ");
    }
    printf(" ]\n");

    if (!ehFolha(noh)) {
        desenhaArvoreBMaisRecursivo(noh->primeiroFilho, nivel + 1, impressao);
        for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
            pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
            desenhaArvoreBMaisRecursivo(pcv->filhoMaior, nivel + 1, impressao);
        }
    }
}

void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {
    if (!arvore->raiz) {
        printf("\n--- Árvore vazia ---\n");
    } else {
        printf("\n--- Representação da árvore B+ ---\n");
        desenhaArvoreBMaisRecursivo(arvore->raiz, 0, fi);
        printf("\n---------------------------------\n");
    }
}

#endif // DESENHA_ARVORE_B_MAIS_TREE_H
