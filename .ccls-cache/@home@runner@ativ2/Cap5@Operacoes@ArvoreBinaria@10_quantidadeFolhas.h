#ifndef QTDEFOLHAS_ARVORE_BINARIA_H
#define QTDEFOLHAS_ARVORE_BINARIA_H
#include "../../ArvoreBinaria.h"
/* -------------------------------------------*/
int quantidadeFolhasRecursiva(pNohArvore raiz){

   if (raiz == NULL)
    return 0;

   if (raiz->esquerda == NULL && raiz->direita == NULL)
      return 1; /*  e uma folha */

   return quantidadeFolhasRecursiva(raiz->esquerda) +
          quantidadeFolhasRecursiva(raiz->direita);

}

/* -------------------------------------------*/
int quantidadeFolhas(pDArvore arvore){
    return quantidadeFolhasRecursiva(arvore->raiz);
}
#endif







