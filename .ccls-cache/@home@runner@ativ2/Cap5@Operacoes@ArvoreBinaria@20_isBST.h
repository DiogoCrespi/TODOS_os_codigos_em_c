#ifndef IS_BST_H
#define IS_BST_H

#include "../../ArvoreBinaria.h"

int isBSTRecursivo(pNohArvore noh, void *min, void *max, FuncaoComparacao fc) {
    if (noh == NULL)
        return 1;

    if ((min != NULL && fc(noh->info, min) <= 0) || (max != NULL && fc(noh->info, max) >= 0))
        return 0;

    return isBSTRecursivo(noh->esquerda, min, noh->info, fc) &&
           isBSTRecursivo(noh->direita, noh->info, max, fc);
}

int isBST(pDArvore arvore, void *min, void *max, FuncaoComparacao fc) {
    if (arvore == NULL || arvore->raiz == NULL)
        return 1;

    return isBSTRecursivo(arvore->raiz, min, max, fc);
}

#endif
