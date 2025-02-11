#ifndef EXCLUIRINFO_ARVORE_PATRICIA_H
#define EXCLUIRINFO_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"

// Função recursiva para remover uma chave da árvore Patricia
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

    // Caminho correto baseado no índice de bits
    if (obterBit(chave, raiz->indice) == 0) {
        raiz->esquerda = removerChavePatriciaRecursivo(raiz->esquerda, chave, removido);
    } else {
        raiz->direita = removerChavePatriciaRecursivo(raiz->direita, chave, removido);
    }

    // Se uma chave foi removida, verificar se o nó interno deve ser eliminado
    if (*removido) {
        // Se um dos filhos for NULL, substituir o nó pelo filho restante
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
            pNohPatricia filhoRestante = (raiz->esquerda != NULL) ? raiz->esquerda : raiz->direita;
            free(raiz);
            return filhoRestante;
        }
    }

    return raiz;
}

// Função pública para remover uma chave da árvore Patricia
int removerChavePatricia(pDPatricia arvore, char *chave) {
    if (arvore == NULL || arvore->raiz == NULL || chave == NULL) {
        return 0; // Árvore vazia ou chave inválida
    }

    int removido = 0;
    arvore->raiz = removerChavePatriciaRecursivo(arvore->raiz, chave, &removido);

    if (removido) {
        arvore->quantidadeChaves--;
    }

    return removido;
}

#endif