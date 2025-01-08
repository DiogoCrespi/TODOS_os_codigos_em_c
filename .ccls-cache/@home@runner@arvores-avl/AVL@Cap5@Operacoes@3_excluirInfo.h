#ifndef EXCLUIRINFO_ARVORE_BINARIA_H
#define EXCLUIRINFO_ARVORE_BINARIA_H
#include "../ArvoreAVL.h"
/* --------------------------*/
pNohArvore excluirInfoRecursivo(pNohArvore raiz, void *info, FuncaoComparacao fc) {
    if (raiz == NULL) {
        return NULL;
    }

    if (fc(raiz->info, info) < 0) {
        raiz->esquerda = excluirInfoRecursivo(raiz->esquerda, info, fc);
    } else if (fc(raiz->info, info) > 0) {
        raiz->direita = excluirInfoRecursivo(raiz->direita, info, fc);
    } else {
        if (raiz->esquerda == NULL) {
            pNohArvore temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            pNohArvore temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        pNohArvore temp = raiz->direita;
        while (temp->esquerda != NULL) {
            temp = temp->esquerda;
        }
        raiz->info = temp->info;
        raiz->direita = excluirInfoRecursivo(raiz->direita, temp->info, fc);
    }

    raiz->fb = (alturaRecursiva(raiz->direita) - alturaRecursiva(raiz->esquerda));

    if (raiz->fb == 2 || raiz->fb == -2) {
        if (raiz->fb == 2) {
            if (raiz->direita->fb >= 0) {
                return rotacaoEsquerda(raiz);
            } else {
                return rotacaoDireitaEsquerda(raiz);
            }
        } else if (raiz->fb == -2) {
            if (raiz->esquerda->fb <= 0) {
                return rotacaoDireita(raiz);
            } else {
                return rotacaoEsquerdaDireita(raiz);
            }
        }
    }

    return raiz;
}

/* ----------------------------------------------------------*/
int excluirInfo(pDArvore arvore, void *info, FuncaoComparacao pfc) {
    if (arvore == NULL) {
        return 0;
    }

    arvore->raiz = excluirInfoRecursivo(arvore->raiz, info, pfc);
    return 1;
}
#endif
