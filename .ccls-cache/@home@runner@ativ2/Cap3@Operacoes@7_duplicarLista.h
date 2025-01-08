#ifndef DUPLICAR_LISTA_H
#define DUPLICAR_LISTA_H
#include "../Lista.h"
pDLista duplicarLista(pDLista pd, FuncaoAlocacao_lista fa)
{
    pDLista pNovaLista = criarLista();

    pNoh atual = pd->primeiro;
    while (atual != NULL)
    {
       /* aloca memoria e copia do valor do campo info */
       void *auxInfo = fa(atual->info);
       /* adiciona a copia da informacao na nova lista */
       incluirInfo_lista(pNovaLista, auxInfo);

       atual = atual->prox;
    }
    return pNovaLista;
}

#endif
