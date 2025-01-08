#ifndef DESENHA_ARVORE_B_MAIS_TREE_H
#define DESENHA_ARVORE_B_MAIS_TREE_H
#include "../BTree.h"
#include "../Utils.h"
#include "../../Cap3/Operacoes/2_incluirInfo.h"

// Função recursiva para desenhar a árvore B+
void desenhaArvoreBTreeRecursivo(pNohBTree raiz, FuncaoImpressao fi, int nivel) {
    if (raiz == NULL) {
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("[ ? ]\n");
        return;
    }

    // Se a lista de chaves for vazia ou o nó não contém chaves
    if (raiz->listaChavesValores == NULL || raiz->listaChavesValores->quantidade == 0) {
        for (int i = 0; i < nivel; i++) printf("  ");
        printf("[ - ]\n");
        return;
    }

    // Desenha o nó atual
    for (int i = 0; i < nivel; i++) printf("  ");
    printf("[ ");

    // Imprime as chaves do nó atual
    for (int i = 0; i < raiz->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i + 1);
        fi(pcv->chave);  // Usando a função de impressão fornecida

        // Adiciona separadores de chave
        if (i < raiz->listaChavesValores->quantidade - 1) {
            printf(" | ");
        }
    }
    printf(" ]\n");

    // Imprime os filhos (primeiro filho e filhos das chaves maiores)
    if (raiz->primeiroFilho != NULL) {
        printf("Filho de [ ");
        for (int i = 0; i < raiz->listaChavesValores->quantidade; i++) {
            pChaveValor pcv = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i + 1);
            fi(pcv->chave);
            if (i < raiz->listaChavesValores->quantidade - 1) {
                printf(" | ");
            }
        }
        printf(" ]:\n");
        desenhaArvoreBTreeRecursivo(raiz->primeiroFilho, fi, nivel + 1);
    }

    // Desenha os filhos das chaves maiores (filho maior)
    for (int i = 0; i < raiz->listaChavesValores->quantidade; i++) {
        pChaveValor pcv = (pChaveValor)buscarInfoPos(raiz->listaChavesValores, i + 1);

        // Desenhando os filhos maiores (subárvore da chave maior)
        if (pcv->filhoMaior != NULL) {
            printf("Filho maior de [ ");
            fi(pcv->chave);  // Imprime a chave maior associada
            printf(" ]:\n");
            desenhaArvoreBTreeRecursivo(pcv->filhoMaior, fi, nivel + 1);
        }
    }
}

// Função principal para desenhar a árvore B+
void desenhaArvore(pDBTree arvore, FuncaoImpressao fi) {
    printf("\n--- Representação da Árvore B+ ---\n");
    desenhaArvoreBTreeRecursivo(arvore->raiz, fi, 0);
    printf("\n---------------------------------\n");
}

#endif
