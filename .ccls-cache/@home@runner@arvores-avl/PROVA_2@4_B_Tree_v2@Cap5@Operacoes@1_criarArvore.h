#ifndef CRIAR_ARVORE_BTREE_H
#define CRIAR_ARVORE_BTREE_H
#include "../BTree.h"

pDBTree criarBTree(int ordem) {
    pDBTree bTree = (pDBTree) malloc(sizeof(DBTree));
    bTree->raiz = NULL;
    bTree->ordem = ordem;
    return bTree;
};

#endif

