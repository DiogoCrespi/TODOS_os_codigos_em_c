#ifndef BUSCAR_ARVORE_PATRICIA_H
#define BUSCAR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"

// Função recursiva para buscar uma chave na árvore Patricia
int buscarChavePatriciaRecursivo(pNohPatricia raiz, char *chave) {
    if (raiz == NULL) {
        return 0; // Chave não encontrada
    }

    if (raiz->ehFolha) {
        return strcmp(raiz->chave, chave) == 0; // Verifica se a chave foi encontrada
    }

    // Seguir o caminho correto baseado no bitIndex do nó interno
    if (obterBit(chave, raiz->indice) == 0) {
        return buscarChavePatriciaRecursivo(raiz->esquerda, chave);
    } else {
        return buscarChavePatriciaRecursivo(raiz->direita, chave);
    }
}

// Função pública para buscar uma chave na árvore Patricia
int buscarChavePatricia(pDPatricia arvore, char *chave) {
    if (arvore == NULL || chave == NULL || arvore->raiz == NULL) {
        return 0; // Árvore vazia ou chave inválida
    }

    return buscarChavePatriciaRecursivo(arvore->raiz, chave);
}

#endif