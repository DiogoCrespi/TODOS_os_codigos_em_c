#ifndef STRUCT_NOH_B_MAIS_TREE_H
#define STRUCT_NOH_B_MAIS_TREE_H

#include "../BTree.h"

#include <stdio.h>
#include <stdlib.h>

// Estrutura para a chave e valor
typedef struct chaveValor {
    void *chave;
    void *valor;
    struct nohBTree *filhoMaior; // Ajustado para refletir sua lógica
} ChaveValor, *pChaveValor;

// Estrutura para o nó da B+ Tree
typedef struct nohBTree {
    pDLista listaChavesValores;  // Lista de chaves e valores
    struct nohBTree* primeiroFilho;  // Ponteiro para o primeiro filho
    struct nohBTree* pai;  // Ponteiro para o nó pai
    struct nohBTree* proxFolha;  // Ponteiro para o próximo nó folha (adicionado)
    int ehFolha;  // Flag que indica se o nó é folha
} NohBTree;


#endif // TAD_BTREE_H

