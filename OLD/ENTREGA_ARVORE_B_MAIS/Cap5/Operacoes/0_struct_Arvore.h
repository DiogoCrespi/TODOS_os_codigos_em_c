#ifndef STRUCT_NOH_B_MAIS_TREE_H
#define STRUCT_NOH_B_MAIS_TREE_H

#include "../BTree.h"

#include <stdio.h>
#include <stdlib.h>


typedef struct chaveValor {
    void *chave;
    void *valor;
    struct nohBTree *filhoMaior;
} ChaveValor, *pChaveValor;


typedef struct nohBTree {
    pDLista listaChavesValores;  
    struct nohBTree* primeiroFilho;  
    struct nohBTree* pai;
    struct nohBTree* proxFolha;
    int ehFolha;
} NohBTree;


#endif //STRUCT_NOH_B_MAIS_TREE_H

