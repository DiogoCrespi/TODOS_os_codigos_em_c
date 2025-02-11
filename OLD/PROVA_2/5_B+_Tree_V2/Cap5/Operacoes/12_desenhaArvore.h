#ifndef DESENHA_ARVORE_B_MAIS_TREE_H
#define DESENHA_ARVORE_B_MAIS_TREE_H

#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"


void desenhaArvoreBMaisRecursivo(pNohBTree noh, int nivel, FuncaoImpressao impressao) {
    if (noh == NULL) return;

    // Imprimir espaços para representar o nível
    for (int i = 0; i < nivel; i++) printf("  ");

    // Imprimir as chaves do nó
    printf("[ ");
    for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
        impressao(pcv->chave);

        // Separador entre as chaves
        if (i < noh->listaChavesValores->quantidade) printf(" - ");
    }
    printf(" ]\n");

    // Desenhar os filhos (apenas se não for folha)
    if (!ehFolha(noh)) {
        if (noh->primeiroFilho != NULL) desenhaArvoreBMaisRecursivo(noh->primeiroFilho, nivel + 1, impressao);
        for (int i = 1; i <= noh->listaChavesValores->quantidade; i++) {
            pChaveValor pcv = (pChaveValor)buscarInfoPos(noh->listaChavesValores, i);
            if (pcv->filhoMaior != NULL) desenhaArvoreBMaisRecursivo(pcv->filhoMaior, nivel + 1, impressao);
        }
    }
}


void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {
    printf("\n--- Representação da Árvore B+ ---\n");
        desenhaArvoreBMaisRecursivo(arvore->raiz, 0, fi);
    printf("\n---------------------------------\n");
}

#endif
