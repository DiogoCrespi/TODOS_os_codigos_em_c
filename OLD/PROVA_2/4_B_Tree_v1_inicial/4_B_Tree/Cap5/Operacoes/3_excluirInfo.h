#ifndef EXCLUIRINFO_BTREE_H
#define EXCLUIRINFO_BTREE_H
#include "../BTree.h"
/* --------------------------*/
pNohBTree excluirInfoBTreeRecursivo(pNohBTree raiz, int ordem, void *chave, FuncaoComparacao fc){


   return NULL;
}

/* ----------------------------------------------------------*/
int excluirInfoBTree(pDBTree arvore, void *chave, FuncaoComparacao pfc){

     pNohBTree novaRaiz = excluirInfoBTreeRecursivo(arvore->raiz, arvore->ordem, chave, pfc);
     if (novaRaiz == NULL){
        printf(" -->> Erro! Chave informada n�o existe na �rvore!!! <<--");
     }
     else{
        arvore->raiz = novaRaiz;
     }

    return 1;

}

#endif
