#ifndef DESENHA_ARVORE_PREFIXO_H
#define DESENHA_ARVORE_PREFIXO_H

#define ESPACO 5

void desenhaArvorePrefixoRecursivo(pNohPrefixo raiz, int depth, char *path, int right) {

    if (raiz == NULL)
        return;

    depth++;

    desenhaArvorePrefixoRecursivo(raiz->direita, depth, path, 1);

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

    printf("%d", raiz->terminal);

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

    desenhaArvorePrefixoRecursivo(raiz->esquerda, depth, path, 0);
}

//----------------------------------------------
void desenhaArvorePrefixo(pDPrefixo arvore) {
    char path[255] = {};

    desenhaArvorePrefixoRecursivo(arvore->raiz, 0, path, 0);
    printf("\n");
}

#endif
