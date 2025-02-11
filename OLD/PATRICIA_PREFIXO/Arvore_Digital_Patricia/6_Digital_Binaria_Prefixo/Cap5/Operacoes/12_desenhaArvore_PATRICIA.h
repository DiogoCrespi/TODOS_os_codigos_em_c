#ifndef DESENHAR_ARVORE_PATRICIA_H
#define DESENHAR_ARVORE_PATRICIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ArvorePatricia.h"

#define ESPACO 5

void desenharArvorePatriciaRecursivo(pNohPatricia raiz, int profundidade, char *caminho, int direita) {
    if (raiz == NULL) {
        return;
    }

    profundidade++;

    desenharArvorePatriciaRecursivo(raiz->direita, profundidade, caminho, 1);

    if (profundidade >= 2) {
        caminho[profundidade - 2] = (direita) ? 1 : 0;
    }

    for (int i = 0; i < profundidade - 1; i++) {
        if (i == profundidade - 2) {
            printf("+");
        } else if (caminho[i]) {
            printf("|");
        } else {
            printf(" ");
        }

        for (int j = 1; j < ESPACO; j++) {
            if (i < profundidade - 2) {
                printf(" ");
            } else {
                printf("-");
            }
        }
    }

    if (raiz->ehFolha) {
        printf(" [%s]\n", raiz->chave ? raiz->chave : "(NULL)");
    } else {
        printf(" (bit %d)\n", raiz->indice);
    }

    desenharArvorePatriciaRecursivo(raiz->esquerda, profundidade, caminho, 0);
}

void desenharArvorePatricia(pDPatricia arvore) {
    if (arvore == NULL || arvore->raiz == NULL) {
        return;
    }

    char caminho[255] = {0};
    printf("\n--- Estrutura da Árvore Patricia ---\n");
    desenharArvorePatriciaRecursivo(arvore->raiz, 0, caminho, 0);
    printf("------------------------------------\n");
}

#endif