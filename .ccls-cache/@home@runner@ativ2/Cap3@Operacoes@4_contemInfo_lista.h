#ifndef CONTEM_INFO_H
#define CONTEM_INFO_H
#include "../Lista.h"
int contemInfo_lista(pDLista pd, void *info, FuncaoComparacao_lista pfc){

    pNoh aux;
    aux = pd->primeiro;

    int i=1;

    while(aux != NULL){

       if (pfc(aux->info, info) == 0)
          return i;

       aux = aux->prox;

       i++;
    }

    return 0;
}
#endif
