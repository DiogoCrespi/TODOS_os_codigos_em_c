#ifndef CRIAR_ARVORE_PATRICIA_H
#define CRIAR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"
#include <stdlib.h>

// Função para criar um nó Patricia
struct nohPatricia* criarNohPatricia(int terminal, int indice) {
    struct nohPatricia* novo = (struct nohPatricia*) malloc(sizeof(struct nohPatricia));
    novo->terminal = terminal;
    novo->indice = indice;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para criar a árvore Patricia
struct dPatricia* criarArvorePatricia() {
    struct dPatricia* dPat = (struct dPatricia*) malloc(sizeof(struct dPatricia));
    dPat->raiz = criarNohPatricia(0, -1); // Raiz inicial sem chave
    dPat->quantidadeNohs = 1;
    return dPat;
}

#endif