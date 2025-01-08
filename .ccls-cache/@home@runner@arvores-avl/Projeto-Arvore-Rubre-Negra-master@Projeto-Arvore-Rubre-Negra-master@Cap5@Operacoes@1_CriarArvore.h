#ifndef CRIAR_ARVORE_RUBRO_H
#define CRIAR_ARVORE_RUBRO_H

#include "../ArvoreRubroNegra.h"

// Função para criar uma nova árvore
pDArvore CriarArvore(int grau) {
    pDArvore dArvore = (pDArvore) malloc(sizeof(DArvore));
    dArvore->raiz = NULL;
    dArvore->quantidadeNohs = 0;
    dArvore->grau = grau;
    dArvore->sentinela = (pNohArvore) malloc(sizeof(NohArvore));
    dArvore->sentinela->cor = BLACK;
    return dArvore;
}


#endif
