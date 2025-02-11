#ifndef EXCLUIRINFO_ARVORE_PATRICIA_H
#define EXCLUIRINFO_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"

pNohPatricia removerChavePatriciaRecursivo(pNohPatricia raiz, char *chave, int nivel, int *removido)
{
    if (raiz == NULL)
    {
        *removido = 0;
        return NULL;
    }

    if (raiz->ehFolha)
    {
        if (strcmp(raiz->chave, chave) == 0)
        {
            free(raiz->chave);
            free(raiz);
            *removido = 1;
            return NULL;
        }
        *removido = 0;
        return raiz;
    }

    pNohPatricia filho;
    if (obterBit(chave, nivel) == 0)
    {
        raiz->esquerda = removerChavePatriciaRecursivo(raiz->esquerda, chave, nivel + 1, removido);
        filho = raiz->esquerda;
    }
    else
    {
        raiz->direita = removerChavePatriciaRecursivo(raiz->direita, chave, nivel + 1, removido);
        filho = raiz->direita;
    }

    if (*removido)
    {
        if (filho == NULL)
        {
            pNohPatricia outroFilho = (obterBit(chave, nivel) == 0) ? raiz->direita : raiz->esquerda;
            free(raiz);
            return outroFilho;
        }
        if (!raiz->esquerda || !raiz->direita)
        {
            pNohPatricia temp = raiz;
            raiz = raiz->esquerda ? raiz->esquerda : raiz->direita;
            free(temp);
        }
    }

    return raiz;
}

int removerChavePatricia(pDPatricia arvore, char *chave)
{
    if (arvore == NULL || arvore->raiz == NULL || chave == NULL)
    {
        return 0;
    }

    int removido = 0;
    arvore->raiz = removerChavePatriciaRecursivo(arvore->raiz, chave, 0, &removido);

    if (removido)
    {
        arvore->quantidadeChaves--;
    }

    return removido;
}

#endif
