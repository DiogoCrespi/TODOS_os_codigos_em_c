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
    struct nohBTree* proximo; 
};

#endif
