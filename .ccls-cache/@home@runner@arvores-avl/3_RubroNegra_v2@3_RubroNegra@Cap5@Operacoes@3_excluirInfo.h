#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include "../ArvoreRubroNegra.h"
#include "../TAD_Arvore.h"
#include "../Utils.h"


/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, pNohArvore sentinela, void *info, FuncaoComparacao pfc) {
    if (raiz == sentinela) {
        return sentinela;
    }

    if (pfc(info, raiz->info) == 0) {
        pNohArvore filho = (raiz->esquerda != sentinela) ? raiz->esquerda : raiz->direita;

        if (raiz->cor == RED || filho->cor == RED) {
            if (filho != sentinela) filho->cor = BLACK;
            return filho;
        }

        filho->cor = DOUBLEBLACK;

        pNohArvore novaRaiz;

        if (raiz->esquerda == filho && raiz->pai->esquerda == raiz) {
            novaRaiz = rotacaoDireita(raiz);
        } else if (raiz->direita == filho && raiz->pai->esquerda == raiz) {
            novaRaiz = rotacaoEsquerdaDireita(raiz);
        } else if (raiz->direita == filho && raiz->pai->direita == raiz) {
            novaRaiz = rotacaoEsquerda(raiz);
        } else if (raiz->esquerda == filho && raiz->pai->direita == raiz) {
            novaRaiz = rotacaoDireitaEsquerda(raiz);
        }

        return novaRaiz;
    } else {
        if (pfc(info, raiz->info) >= 0) {
            pNohArvore filho = excluirInfoRecursivo(raiz->esquerda, sentinela, info, pfc);
            raiz->esquerda = filho;
        } else {
            pNohArvore filho = excluirInfoRecursivo(raiz->direita, sentinela, info, pfc);
            raiz->direita = filho;
        }

        if (raiz->pai == NULL) {
            raiz->cor = BLACK;
            return raiz;
        }

        if (raiz->cor == BLACK || (raiz->cor == RED && (raiz->esquerda->cor == BLACK || raiz->direita->cor == BLACK))) {
            return raiz;
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    printf("\n ----------- Excluindo info: %d ---\n", *((int*)info));
    pNohArvore novaRaiz = excluirInfoRecursivo(arvore->raiz, arvore->sentinela, info, pfc);
    if (novaRaiz != NULL) {
        arvore->raiz = novaRaiz;
        arvore->raiz->cor = BLACK;
        arvore->quantidadeNohs--;
    } else {
        printf("\n --> Chave não encontrada! <--");
    }

    printf("\n -----------------------------------------");
    desenhaArvore(arvore, imprimeInt);
    printf("\n ----------------------------------------- \n");

    return (novaRaiz != NULL) ? 1 : 0;
}

#endif
