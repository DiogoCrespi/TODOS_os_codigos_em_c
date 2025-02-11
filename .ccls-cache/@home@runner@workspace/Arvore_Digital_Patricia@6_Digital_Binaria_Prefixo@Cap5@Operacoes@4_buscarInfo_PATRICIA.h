#ifndef BUSCAR_ARVORE_PATRICIA_H
#define BUSCAR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"

int buscarChavePatriciaRecursivo(pNohPatricia raiz, char *chave, int nivel)
{
    if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->ehFolha)
    {
        return strcmp(raiz->chave, chave) == 0;
    }

    if (obterBit(chave, nivel) == 0)
    {
        return buscarChavePatriciaRecursivo(raiz->esquerda, chave, nivel + 1);
    }
    else
    {
        return buscarChavePatriciaRecursivo(raiz->direita, chave, nivel + 1);
    }
}

int buscarChavePatricia(pDPatricia arvore, char *chave)
{
    if (arvore == NULL || chave == NULL || arvore->raiz == NULL)
    {
        return 0;
    }

    return buscarChavePatriciaRecursivo(arvore->raiz, chave, 0);
}

#endif
