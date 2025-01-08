#ifndef IGUAIS_ARVORE_H
#define IGUAIS_ARVORE_H
#include "../../ArvoreBinaria.h"
int iguaisRecursivo(pNohArvore noh1, pNohArvore noh2, FuncaoComparacao fc) {
  if (noh1 == NULL && noh2 == NULL)
      return 1;

  if (noh1 == NULL || noh2 == NULL)
      return 0;

  if (fc(noh1->info, noh2->info) != 0)
      return 0;

  return iguaisRecursivo(noh1->esquerda, noh2->esquerda, fc) &&
         iguaisRecursivo(noh1->direita, noh2->direita, fc);
}

int iguais(pDArvore arvore1, pDArvore arvore2, FuncaoComparacao fc) {
  if (arvore1 == NULL && arvore2 == NULL)
      return 1;

  if (arvore1 == NULL || arvore2 == NULL)
      return 0;

  return iguaisRecursivo(arvore1->raiz, arvore2->raiz, fc);
}
#endif