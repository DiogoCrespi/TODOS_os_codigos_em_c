#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H
#include "../ArvoreRubroNegra.h"
#include "../TAD_Arvore.h"
#include "../Utils.h"
#ifndef CRIAR_ARVORE_BINARIA_H
#define CRIAR_ARVORE_BINARIA_H

//---------------------------------------
pNohArvore RotacaoDireita(pNohArvore raiz)
{
    pNohArvore u;
    u = raiz->esquerda;
    raiz->esquerda = u->direita;
    u->direita = raiz;
    return u;
}

//---------------------------------------
pNohArvore RotacaoEsquerda(pNohArvore raiz)
{
    pNohArvore u;
    u = raiz->direita;
    raiz->direita = u->esquerda;
    u->esquerda = raiz;
    return u;
}

//---------------------------------------
pNohArvore RotacaoEsquerdaDireita(pNohArvore raiz)
{
    raiz->esquerda = RotacaoEsquerda(raiz->esquerda);
    return RotacaoDireita(raiz);
}

//---------------------------------------
pNohArvore RotacaoDireitaEsquerda(pNohArvore raiz)
{
    raiz->direita = RotacaoDireita(raiz->direita);
    return RotacaoEsquerda(raiz);
}

/* --------------------------*/
pNohArvore IncluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc)
{

    if (raiz == NULL)
    {
        pNohArvore pnh = malloc(sizeof(NohArvore));
        pnh->info = info;
        pnh->esquerda = NULL;
        pnh->direita = NULL;
        pnh->fb = 0;
        return pnh;
    }

    if (pfc(raiz->info, info) <= 0)
    {
        raiz->esquerda = IncluirInfoRecursivo(raiz->esquerda, info, pfc);
    }
    else
    {
        raiz->direita = IncluirInfoRecursivo(raiz->direita, info, pfc);
    }

    raiz->fb = AlturaRecursiva(raiz->direita) - AlturaRecursiva(raiz->esquerda);

    if (raiz->fb == 2 || raiz->fb == -2)
    {

        if (raiz->fb == 2)
        {
            if ((raiz->direita != NULL && (raiz->direita->fb == 1 || raiz->direita->fb == 0)) ||
                (raiz->esquerda != NULL && (raiz->esquerda->fb == 1 || raiz->esquerda->fb == 0)))
            {

                pNohArvore novaRaiz = RotacaoEsquerda(raiz);
                CalcularFatorBalanceamentoRecursivo(novaRaiz);
                return novaRaiz;
            }

            if ((raiz->direita != NULL && raiz->direita->fb == -1) ||
                (raiz->esquerda != NULL && raiz->esquerda->fb == -1))
            {

                pNohArvore novaRaiz = RotacaoDireitaEsquerda(raiz);
                CalcularFatorBalanceamentoRecursivo(novaRaiz);
                return novaRaiz;
            }
        }

        if (raiz->fb == -2)
        {
            if ((raiz->direita != NULL && (raiz->direita->fb == -1 || raiz->direita->fb == 0)) ||
                (raiz->esquerda != NULL && (raiz->esquerda->fb == -1 || raiz->esquerda->fb == 0)))
            {
                printf(" -> Rotacao simples Direita <- ");

                pNohArvore novaRaiz = RotacaoDireita(raiz);
                CalcularFatorBalanceamentoRecursivo(novaRaiz);
                return novaRaiz;
            }

            if ((raiz->direita != NULL && raiz->direita->fb == 1) || (raiz->esquerda != NULL && raiz->esquerda->fb == 1))
            {
                pNohArvore novaRaiz = RotacaoEsquerdaDireita(raiz);
                CalcularFatorBalanceamentoRecursivo(novaRaiz);
                return novaRaiz;
            }
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
void IncluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc)
{
    if (arvore->raiz == NULL || pfc(arvore->raiz->info, info) != 0)
    {
        arvore->raiz = IncluirInfoRecursivo(arvore->raiz, info, pfc);
    }
}
#endif