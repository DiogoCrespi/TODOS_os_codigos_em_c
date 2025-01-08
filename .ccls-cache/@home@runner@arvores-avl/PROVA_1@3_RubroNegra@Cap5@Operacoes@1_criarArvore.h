#ifndef CRIAR_ARVORE_RUBRO_H
#define CRIAR_ARVORE_RUBRO_H

#include "../ArvoreRubroNegra.h"

// Função para criar uma nova árvore
pDArvore criarArvore(int grau) {
    pDArvore novaArvore = (pDArvore) malloc(sizeof(DArvore));
    novaArvore->raiz = novaArvore->sentinela = (pNohArvore) malloc(sizeof(NohArvore));
    novaArvore->sentinela->cor = BLACK;
    novaArvore->sentinela->esquerda = novaArvore->sentinela->direita = novaArvore->sentinela->pai = NULL;
    novaArvore->quantidadeNohs = 0;
    novaArvore->grau = grau;
    return novaArvore;
}




#endif
