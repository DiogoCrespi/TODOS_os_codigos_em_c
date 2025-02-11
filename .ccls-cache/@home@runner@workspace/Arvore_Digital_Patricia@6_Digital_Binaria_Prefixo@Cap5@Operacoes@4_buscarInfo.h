
#ifndef BUSCAR_INFO_PATRICIA_H
#define BUSCAR_INFO_PATRICIA_H

#include "../ArvorePatricia.h"

int buscarInfoPatriciaRecursivo(struct nohPatricia* noh, char chave[], int k) {
    if (noh == NULL) return 0;
    if (noh->terminal) return 1;

    if (chave[noh->indice] == '0') {
        return buscarInfoPatriciaRecursivo(noh->esquerda, chave, k);
    } else {
        return buscarInfoPatriciaRecursivo(noh->direita, chave, k);
    }
}

int buscarInfoPatricia(struct dPatricia* arvore, char chave[], int k) {
    return buscarInfoPatriciaRecursivo(arvore->raiz, chave, k);
}

#endif