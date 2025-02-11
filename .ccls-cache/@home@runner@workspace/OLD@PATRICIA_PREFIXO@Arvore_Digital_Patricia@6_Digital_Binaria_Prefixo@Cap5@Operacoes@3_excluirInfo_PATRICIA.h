#ifndef EXCLUIRINFO_ARVORE_PATRICIA_H
#define EXCLUIRINFO_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"


pNohPatricia removerChavePatriciaRecursivo(pNohPatricia raiz, char *chave, int *removido) {
    if (raiz == NULL) {
        *removido = 0;
        return NULL;
    }

    if (raiz->ehFolha) {
        if (strcmp(raiz->chave, chave) == 0) {
            free(raiz->chave);
            free(raiz);
            *removido = 1;
            return NULL;
        }
        *removido = 0;
        return raiz;
    }

    if (obterBit(chave, raiz->indice) == 0) {
        raiz->esquerda = removerChavePatriciaRecursivo(raiz->esquerda, chave, removido);
    } else {
        raiz->direita = removerChavePatriciaRecursivo(raiz->direita, chave, removido);
    }

    if (*removido) {
 
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            pNohPatricia filhoRestante = (raiz->esquerda != NULL) ? raiz->esquerda : raiz->direita;
            free(raiz);
            return filhoRestante;
        }
    }

    return raiz;
}

int removerChavePatricia(pDPatricia arvore, char *chave) {
    if (arvore == NULL || arvore->raiz == NULL || chave == NULL) {
        return 0; 
    }

    int removido = 0;
    arvore->raiz = removerChavePatriciaRecursivo(arvore->raiz, chave, &removido);

    if (removido) {
        arvore->quantidadeChaves--;
    }

    return removido;
}

#endif