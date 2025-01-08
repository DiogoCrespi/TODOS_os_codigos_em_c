#ifndef CRIAR_ARVORE_H
#define CRIAR_ARVORE_H
#include "../ArvoreRubroNegra.h"
#include "../Utils.h"
pDArvore CriarArvore(int valorRaiz)
{
    pDArvore dArvore = (pDArvore) malloc(sizeof(DArvore));
    dArvore->raiz =  (pNohArvore) malloc(sizeof(NohArvore));
    dArvore->raiz->info = AlocaInt(valorRaiz);
    dArvore->raiz->esquerda = NULL;
    dArvore->raiz->direita = NULL;
    dArvore->quantidadeNohs = 1;
    dArvore->grau = 2; // Supondo que é uma árvore binária
    return dArvore;
}

#endif