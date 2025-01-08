#ifndef INCLUIR_INFO_POS_H
#define INCLUIR_INFO_POS_H
#include "../Lista.h"
void inserirInfoPos(pDLista lista, int pos, void* info) {
    if (pos < 0 || pos > lista->quantidade) {
        // Handle invalid position
        return;
    }

    pNoh novoNoh = malloc(sizeof(Noh));
    novoNoh->info = info;
    novoNoh->prox = NULL;

    if (pos == 0) {
        // Incluir no início da lista
        if (lista->quantidade == 0) {
            lista->primeiro = novoNoh;
            lista->ultimo = novoNoh;
        } else {
            novoNoh->prox = lista->primeiro;
            lista->primeiro = novoNoh;
        }
    } else if (pos == lista->quantidade) {
        // Incluir no final da lista
        lista->ultimo->prox = novoNoh;
        lista->ultimo = novoNoh;
    } else {
        // Incluir no meio da lista
        pNoh nohAtual = lista->primeiro;
        for (int i = 1; i < pos; i++) {
            nohAtual = nohAtual->prox;
        }
        novoNoh->prox = nohAtual->prox;
        nohAtual->prox = novoNoh;
    }

    lista->quantidade++;
}
#endif