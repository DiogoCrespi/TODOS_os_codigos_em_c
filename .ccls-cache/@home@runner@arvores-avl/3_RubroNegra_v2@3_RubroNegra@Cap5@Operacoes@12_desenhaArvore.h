#ifndef DESENHA_ARVORE_H
#define DESENHA_ARVORE_H
#include "../ArvoreRubroNegra.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ESPACO 5

void desenhaArvoreRecursivo(pNohArvore raiz, pNohArvore sentinela, int depth, char *path, int right, FuncaoImpressao fi) {

    if (raiz == NULL || raiz == sentinela)
        return;

    depth++;

    desenhaArvoreRecursivo(raiz->direita, sentinela, depth, path, 1, fi);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(raiz->esquerda)
        path[depth-1] = 1;

    printf("\n");
    int i;
    for(i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    fi(raiz->info);
    printf("[%c]", raiz->cor);

    for(i=0; i<depth; i++)
    {
      if(path[i])
          printf(" ");
      else
          printf(" ");

      int j;
      for(j=1; j<ESPACO; j++)
          printf(" ");
    }

    desenhaArvoreRecursivo(raiz->esquerda, sentinela, depth, path, 0, fi);
}

void desenhaArvore(pDArvore arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRecursivo(arvore->raiz, arvore->sentinela, 0, path, 0, fi);
    printf("\n");
}

#endif
