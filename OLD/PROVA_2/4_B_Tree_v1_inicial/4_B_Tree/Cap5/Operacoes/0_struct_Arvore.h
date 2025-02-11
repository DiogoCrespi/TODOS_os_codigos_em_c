#ifndef STRUCT_NOH_BTREE_H
#define STRUCT_NOH_BTREE_H
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
};

#endif
