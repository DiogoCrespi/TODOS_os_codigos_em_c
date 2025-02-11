#ifndef BUSCAR_INFO_BTREE_H
#define BUSCAR_INFO_BTREE_H
#include "../BTree.h"
pNohBTree buscarInfoBTreeRecursivo (pNohBTree raiz, void *chave, FuncaoComparacao pfc)
{
    return NULL;
}


/* ----------------------------------------------------------*/
void* buscarInfoBTree (pDBTree arvore, void *chave, FuncaoComparacao pfc)
{
    return buscarInfoBTreeRecursivo(arvore->raiz, chave, pfc);

}

#endif

