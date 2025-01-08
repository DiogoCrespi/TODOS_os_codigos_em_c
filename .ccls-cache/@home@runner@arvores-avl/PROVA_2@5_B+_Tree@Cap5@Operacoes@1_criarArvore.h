#ifndef CRIAR_ARVORE_B_MAIS_TREE_H
#define CRIAR_ARVORE_B_MAIS_TREE_H
#include "../BTree.h"

pDBTree criarBTree(int ordem) {
    pDBTree bTree = (pDBTree) malloc(sizeof(DBTree));
    bTree->raiz = NULL;
    bTree->ordem = ordem;
    return bTree;
}

#endif
