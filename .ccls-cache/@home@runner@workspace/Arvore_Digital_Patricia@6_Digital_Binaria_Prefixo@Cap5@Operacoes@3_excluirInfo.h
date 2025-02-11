
#ifndef EXCLUIR_INFO_PATRICIA_H
#define EXCLUIR_INFO_PATRICIA_H

#include "../ArvorePatricia.h"

struct nohPatricia* excluirInfoPatriciaRecursivo(struct nohPatricia* noh, char chave[], int k) {
    if (noh == NULL) return NULL;

    if (noh->terminal) {
        free(noh);
        return NULL;
    }

    if (chave[noh->indice] == '0') {
        noh->esquerda = excluirInfoPatriciaRecursivo(noh->esquerda, chave, k);
    } else {
        noh->direita = excluirInfoPatriciaRecursivo(noh->direita, chave, k);
    }

    return noh;
}

int excluirInfoPatricia(struct dPatricia* arvore, char chave[], int k) {
    arvore->raiz = excluirInfoPatriciaRecursivo(arvore->raiz, chave, k);
    arvore->quantidadeNohs--;
    return 1;
}

#endif