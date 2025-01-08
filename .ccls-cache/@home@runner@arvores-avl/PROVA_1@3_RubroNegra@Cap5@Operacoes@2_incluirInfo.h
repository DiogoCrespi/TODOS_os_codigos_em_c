#ifndef INCLUIR_INFO_RUBRO_NEGRA_H
#define INCLUIR_INFO_RUBRO_NEGRA_H

#include "../ArvoreRubroNegra.h"
#include "../TAD_Arvore.h"
#include "../Utils.h"

/* ---------------------------------------------------------------------*/
pNohArvore Avo(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL) return NULL;
    return raiz->pai->pai;
}
/* ---------------------------------------------------------------------*/
pNohArvore Tio(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL) return NULL;
    if (Avo(raiz) != NULL && Avo(raiz)->esquerda == raiz->pai) return Avo(raiz)->direita;
    return Avo(raiz)->esquerda;
}
/* ---------------------------------------------------------------------*/
char CorTio(pNohArvore raiz) {
    pNohArvore tioRaiz = Tio(raiz);
    if (tioRaiz == NULL) return 'X';
    return tioRaiz->cor;
}
/* ---------------------------------------------------------------------*/
pNohArvore rotacaoDireita(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL) return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    avoRaiz->pai = raiz->pai;
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->esquerda = raiz->pai->direita;
    raiz->pai->direita = avoRaiz;
    raiz->pai->cor = BLACK;
    avoRaiz->cor = RED;
    return raiz->pai;
}
/* ---------------------------------------------------------------------*/
pNohArvore rotacaoEsquerda(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL) return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    raiz->pai->pai = avoRaiz->pai;
    avoRaiz->pai = raiz->pai;
    avoRaiz->direita = raiz->pai->esquerda;
    raiz->pai->esquerda = avoRaiz;
    raiz->pai->cor = BLACK;
    avoRaiz->cor = RED;
    return raiz->pai;
}
/* ---------------------------------------------------------------------*/
pNohArvore rotacaoEsquerdaDireita(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL) return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    pNohArvore paiRaiz = raiz->pai;
    paiRaiz->pai = raiz;
    raiz->pai = avoRaiz;
    paiRaiz->direita = raiz->esquerda;
    raiz->esquerda = paiRaiz;
    return rotacaoDireita(paiRaiz);
}
/* ---------------------------------------------------------------------*/
pNohArvore rotacaoDireitaEsquerda(pNohArvore raiz) {
    if (raiz == NULL || raiz->pai == NULL || Avo(raiz) == NULL) return NULL;
    pNohArvore avoRaiz = Avo(raiz);
    pNohArvore paiRaiz = raiz->pai;
    paiRaiz->pai = raiz;
    raiz->pai = avoRaiz;
    paiRaiz->esquerda = raiz->direita;
    raiz->direita = paiRaiz;
    return rotacaoEsquerda(paiRaiz);
}
/* ---------------------------------------------------------------------*/
pNohArvore incluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao pfc, pNohArvore sentinela) {
    if (raiz == sentinela) {
        raiz = (pNohArvore) malloc(sizeof(NohArvore));
        raiz->info = info;
        raiz->esquerda = sentinela;
        raiz->direita = sentinela;
        raiz->pai = sentinela;
        raiz->cor = RED;
        return raiz;
    } else {
        pNohArvore filho;
        if (pfc(info, raiz->info) >= 0) {
            filho = incluirInfoRecursivo(raiz->esquerda, info, pfc, sentinela);
            if (filho->direita == raiz) raiz = filho;
            else {
                filho->pai = raiz;
                raiz->esquerda = filho;
            }
        } else {
            filho = incluirInfoRecursivo(raiz->direita, info, pfc, sentinela);
            if (filho->esquerda == raiz) raiz = filho;
            else {
                filho->pai = raiz;
                raiz->direita = filho;
            }
        }
        if (raiz->pai == sentinela) {
            raiz->cor = BLACK;
            return raiz;
        }
        if (raiz->cor == BLACK || (raiz->cor == RED && filho->cor == BLACK)) return raiz;
        if (raiz->cor == RED && CorTio(filho) == RED) {
            raiz->cor = BLACK;
            Tio(filho)->cor = BLACK;
            if (Avo(filho) != sentinela) Avo(filho)->cor = RED;
            return raiz;
        }
        if (raiz->cor == RED && CorTio(filho) != RED) {
            pNohArvore novaRaiz;
            if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) novaRaiz = rotacaoDireita(filho);
            else if (raiz->direita == filho && raiz->pai->esquerda == raiz) novaRaiz = rotacaoEsquerdaDireita(filho);
            else if (raiz->direita == filho && raiz->pai->direita == raiz) novaRaiz = rotacaoEsquerda(filho);
            else if (raiz->esquerda == filho && raiz->pai->direita == raiz) novaRaiz = rotacaoDireitaEsquerda(filho);
            return novaRaiz;
        }
    }
    return raiz;
}
/* ----------------------------------------------------------*/
void incluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    printf("\n  ---------- Incluindo: %d ---------- \n", *((int *)info));
    arvore->raiz = incluirInfoRecursivo(arvore->raiz, info, pfc, arvore->sentinela);
    arvore->raiz->cor = BLACK;
    arvore->quantidadeNohs++;
    printf("\n------------    Arvore:    ------------ \n");
    desenhaArvore(arvore, imprimeInt);
    printf("\n--------------------------------------- \n");
}

#endif
