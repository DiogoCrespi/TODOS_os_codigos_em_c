#ifndef STRUCT_NOH_B_MAIS_TREE_H
#define STRUCT_NOH_B_MAIS_TREE_H

#include "../BTree.h"

struct chaveValor {
    void* chave;
    void* valor;
    struct nohBTree* filhoMaior;
};

struct nohBTree {
    pDLista listaChavesValores;
    struct nohBTree* primeiroFilho;
    struct nohBTree* pai;
    struct nohBTree* proximo;  // Ponteiro para o próximo nó (em folhas)
    int ehFolha;              // Flag para identificar se o nó é uma folha
    struct nohBTree* proxFolha; // Ponteiro para o próximo nó folha
};
int ehFolha(pNohBTree noh) {
    return noh != NULL && noh->ehFolha;
}

#endif
