#ifndef EXCLUIR_INFO_POS_H
#define EXCLUIR_INFO_POS_H
#include "../Lista.h"

void* excluirInfoPos(pDLista pd, int pos) {
    if (pd == NULL || pos < 1 || pos > pd->quantidade) {
        return NULL; // Verificação de limites e lista nula
    }

    int cont = 1;
    pNoh atual = pd->primeiro, ant = NULL;

    // Navega até a posição desejada
    while (atual != NULL && cont < pos) {
        ant = atual;
        atual = atual->prox;
        cont++;
    }

    if (atual != NULL) {
        if (ant == NULL) {
            pd->primeiro = atual->prox; // Caso seja o primeiro elemento
        } else {
            ant->prox = atual->prox; // Caso esteja no meio ou fim
        }

        if (atual == pd->ultimo) {
            pd->ultimo = ant; // Atualiza o último elemento
        }

        if (pd->quantidade == 1) { // Caso fosse o único elemento
            pd->primeiro = NULL;
            pd->ultimo = NULL;
        }

        pd->quantidade--;
        void* auxInfo = atual->info;
        free(atual);
        return auxInfo;
    }

    return NULL; // Caso não encontre a posição
}

#endif // EXCLUIR_INFO_POS_H
