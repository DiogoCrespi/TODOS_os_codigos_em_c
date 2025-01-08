#ifndef BUSCAR_INFO_POS_H
#define BUSCAR_INFO_POS_H
#include "../Lista.h"

void* buscarInfoPos(pDLista lista, int pos) {
    if (lista == NULL || pos < 1 || pos > lista->quantidade) {
        return NULL; // Verificação de limites e lista nula
    }

    pNoh atual = lista->primeiro;
    int cont = 1;

    while (atual != NULL) {
        if (cont == pos) {
            return atual->info; // Retorna a informação encontrada
        }
        atual = atual->prox;
        cont++;
    }

    return NULL; // Caso não encontre a posição
}

#endif // BUSCAR_INFO_POS_H
