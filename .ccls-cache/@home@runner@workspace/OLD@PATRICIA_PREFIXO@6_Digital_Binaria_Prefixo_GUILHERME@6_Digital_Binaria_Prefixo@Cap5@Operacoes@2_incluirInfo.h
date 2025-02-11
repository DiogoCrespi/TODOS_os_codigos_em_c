#ifndef INCLUIR_ARVORE_PATRICIA_H
#define INCLUIR_ARVORE_PATRICIA_H
#include "../ArvorePrefixo.h"
#include "../Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao recursiva para incluir uma chave na arvore Patricia
NohPatricia *incluirChaveRecursivo(NohPatricia *raiz, const char *chave, int nivel) {
    if (raiz == NULL) {
        // Criar um no folha com a chave
        NohPatricia *novoNo = (NohPatricia*) malloc(sizeof(NohPatricia));
        novoNo->ehFolha = 1;
        novoNo->bitIndex = -1;  // Nao ha bitIndex em nos folha
        novoNo->chave = strdup(chave);
        novoNo->esquerda = novoNo->direita = NULL;
        return novoNo;
    }

    if (raiz->ehFolha) {
        // Caso de no folha: comparar bit por bit
        int i = 0;
        while (chave[i] == raiz->chave[i] && chave[i] != '\0' && raiz->chave[i] != '\0') {
            i++;
        }

        if (chave[i] != raiz->chave[i]) {
            // Se as chaves nao coincidem, dividir o no folha
            NohPatricia *novoInterno = (NohPatricia*) malloc(sizeof(NohPatricia));
            novoInterno->ehFolha = 0;
            novoInterno->bitIndex = i;  // O bit onde ocorre a diferenca
            novoInterno->chave = NULL;  // Nao possui chave no no interno

            // Criar novos nos para as duas subarvores
            novoInterno->esquerda = criarNohFolha(raiz->chave);
            novoInterno->direita = criarNohFolha(chave);

            // Liberar o no folha antigo
            free(raiz->chave);
            free(raiz);

            return novoInterno;
        }

        return raiz;  // Chave ja existe, nao precisa modificar
    }

    // Caso de no interno: decidir se vamos para a esquerda ou direita
    if (obterBit(chave, nivel) == 0) {
        raiz->esquerda = incluirChaveRecursivo(raiz->esquerda, chave, nivel + 1);
    } else {
        raiz->direita = incluirChaveRecursivo(raiz->direita, chave, nivel + 1);
    }

    return raiz;
}

// Funcao para incluir uma chave na arvore Patricia
int incluirChave(DPatricia *arvore, const char *chave) {
    if (arvore->raiz == NULL) {
        // Se a arvore esta vazia, criamos a raiz com a chave
        arvore->raiz = incluirChaveRecursivo(NULL, chave, 0);
        return 1;
    }
    arvore->raiz = incluirChaveRecursivo(arvore->raiz, chave, 0);
    return 1;
}

#endif
