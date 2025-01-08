#ifndef DUPLICAR_LISTA_H
#define DUPLICAR_LISTA_H
#include "../Lista.h"
#include "../TAD_ListaLinear.h"
pDLista duplicarLista(pDLista pd, FuncaoAlocacao fa)
{
    pDLista pNovaLista = criarLista();

    pNoh atual = pd->primeiro;
    while (atual != NULL)
    {
       /* aloca memoria e copia do valor do campo info */
       void *auxInfo = fa(atual->info);
       /* adiciona a copia da informacao na nova lista */
       incluirInfo(pNovaLista, auxInfo);

       atual = atual->prox;
    }
    return pNovaLista;
}

#endif
