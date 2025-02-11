#ifndef CRIAR_ARVORE_PATRICIA_H
#define CRIAR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"
#include "0_struct_Arvore_PATRICIA.h"
#include "0_struct_Descritor_PATRICIA.h"

pNohPatricia criarNohPatricia(int ehFolha, int indice)
{
    pNohPatricia pNovo = (pNohPatricia)malloc(sizeof(NohPatricia));
    if (pNovo == NULL)
    {
        return NULL;
    }

    pNovo->ehFolha = ehFolha;
    pNovo->indice = indice;
    pNovo->esquerda = NULL;
    pNovo->direita = NULL;
    pNovo->chave = NULL;

    return pNovo;
}

pDPatricia criarArvorePatricia()
{
    pDPatricia dPat = (pDPatricia)malloc(sizeof(DPatricia));
    if (dPat == NULL)
    {
        return NULL;
    }

    dPat->raiz = NULL;
    dPat->quantidadeChaves = 0;

    return dPat;
}

#endif
