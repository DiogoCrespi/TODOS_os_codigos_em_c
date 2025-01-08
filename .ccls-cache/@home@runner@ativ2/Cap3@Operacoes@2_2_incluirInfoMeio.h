#ifndef INCLUIR_INFO_MEIO_H
#define INCLUIR_INFO_MEIO_H
#include "../Lista.h"
void incluirInfoMeio_lista(pDLista pd, void *info, int pos){

    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }

    if(pd->quantidade == 0){
        incluirInfo_lista(pd, info);
        return;
    }

     if(pos > pd->quantidade){
        incluirInfo_lista(pd, info);
        return;
    }

     if(pos == 1){
        incluirInfoInicio_lista(pd, info);
        return;
    }

    int contador = 1;
    pNoh ant, atual;
    atual = pd->primeiro;
    ant = NULL;
    while (contador < pos){

        ant = atual;
        atual = atual->prox;
        contador++;
    }

      /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informacao no campo "info" do novo noh alocado */
    pNovo->info = info;

    ant->prox = pNovo;
    pNovo->prox = atual;
    pd->quantidade++;
}

#endif
