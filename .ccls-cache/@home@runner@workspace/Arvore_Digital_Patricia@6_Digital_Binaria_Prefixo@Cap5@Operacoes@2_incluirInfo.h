
#ifndef INSERIR_INFO_PATRICIA_H
#define INSERIR_INFO_PATRICIA_H

#include "../ArvorePatricia.h"

// Inserir recursivamente em uma árvore Patricia
struct nohPatricia* inserirInfoPatriciaRecursivo(struct nohPatricia* noh, char chave[], int k, int l) {
    if (noh == NULL) {
        return criarNohPatricia(1, l); // Nó terminal
    }

    if (noh->terminal) {
        int i;
        for (i = 0; i < k && chave[i] == '0'; i++);
        if (i == k) return noh; // Chave já existe

        struct nohPatricia* novo = criarNohPatricia(1, i);
        if (chave[i] == '0') {
            novo->esquerda = noh;
        } else {
            novo->direita = noh;
        }
        return novo;
    }

    if (chave[noh->indice] == '0') {
        noh->esquerda = inserirInfoPatriciaRecursivo(noh->esquerda, chave, k, l);
    } else {
        noh->direita = inserirInfoPatriciaRecursivo(noh->direita, chave, k, l);
    }

    return noh;
}

// Inserir chave na árvore Patricia
int inserirInfoPatricia(struct dPatricia* arvore, char chave[], int k) {
    arvore->raiz = inserirInfoPatriciaRecursivo(arvore->raiz, chave, k, 0);
    arvore->quantidadeNohs++;
    return 1;
}

#endif