#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H
#include "../ArvoreRubroNegra.h"
/* --------------------------*/
pDArvore criarArvore(int grau){
    pDArvore dArvore = (pDArvore) malloc(sizeof(DArvore));
    dArvore->raiz = NULL;
    dArvore->quantidadeNohs = 0;
    dArvore->grau  = grau;
    // sentinela
    dArvore->sentinela = (pNohArvore) malloc(sizeof(NohArvore));
    dArvore->sentinela->cor = BLACK;

    return dArvore;
};

#endif
