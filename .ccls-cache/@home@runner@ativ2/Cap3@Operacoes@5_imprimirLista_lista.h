#ifndef IMPRIMIR_LISTA_H
#define IMPRIMIR_LISTA_H
#include "../Lista.h"
void imprimirLista(pDLista pd, FuncaoImpressao_lista pfi){

    pNoh aux;
    aux = pd->primeiro;

    while(aux != NULL){
       /*printf("%d", *(((int *)aux->info)));*/
       pfi(aux->info);

       aux = aux->prox;

    }
}

#endif
