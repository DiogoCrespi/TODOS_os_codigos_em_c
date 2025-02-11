#ifndef CRIAR_ARVORE_B_MAIS_TREE_H
#define CRIAR_ARVORE_B_MAIS_TREE_H
#include "../BTree.h"

pDBTree criarBTree(int ordem) {
    pDBTree bTree = (pDBTree) malloc(sizeof(DBTree));
    bTree->raiz = NULL;
    bTree->ordem = ordem;
    return bTree;
}

pNohBTree criarNohBMais(int ehFolha) {
    pNohBTree noh = (pNohBTree) malloc(sizeof(struct nohBTree));
    noh->listaChavesValores = criarLista();
    noh->primeiroFilho = NULL;
    noh->pai = NULL;
    noh->proximo = NULL;
    noh->proxFolha = NULL;
    noh->ehFolha = ehFolha;
    return noh;
}

#endif
