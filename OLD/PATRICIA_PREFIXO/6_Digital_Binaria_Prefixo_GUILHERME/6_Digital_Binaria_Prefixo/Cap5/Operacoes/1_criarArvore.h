#ifndef CRIAR_ARVORE_PATRICIA_H
#define CRIAR_ARVORE_PATRICIA_H
#include "../ArvorePrefixo.h"
#include <stdlib.h>
#include <string.h>

//---------------------------------
NohPatricia *criarNohFolha(const char *chave) {
    NohPatricia *pNovo = (NohPatricia *)malloc(sizeof(NohPatricia));
    pNovo->ehFolha = 1;
    pNovo->bitIndex = -1;
    pNovo->chave = strdup(chave);
    pNovo->esquerda = NULL;
    pNovo->direita = NULL;
    return pNovo;
}

//---------------------------------
NohPatricia *criarNohInterno(int bitIndex, NohPatricia *esquerda, NohPatricia *direita) {
    NohPatricia *pNovo = (NohPatricia *)malloc(sizeof(NohPatricia));
    pNovo->ehFolha = 0;
    pNovo->bitIndex = bitIndex;
    pNovo->chave = NULL;
    pNovo->esquerda = esquerda;
    pNovo->direita = direita;
    return pNovo;
}

//---------------------------------
DPatricia *criarArvorePatricia() {
    DPatricia *dPat = (DPatricia*)malloc(sizeof(DPatricia));
    dPat->raiz = NULL; // Inicialmente, a raiz e NULL
    return dPat;
}

#endif
