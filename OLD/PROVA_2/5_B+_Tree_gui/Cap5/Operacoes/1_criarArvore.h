#ifndef CRIAR_ARVORE_B_MAIS_TREE_H
#define CRIAR_ARVORE_B_MAIS_TREE_H
#include "../BTree.h"

pDBTree criarBTree(int ordem) {
    pDBTree arvore = malloc(sizeof(DBTree));
    if (!arvore) {
        printf("Erro ao alocar memória para a árvore.\n");
        exit(1);
    }

    arvore->raiz = NULL;
    arvore->ordem = ordem;
    return arvore;
}

#endif // CRIAR_ARVORE_H

