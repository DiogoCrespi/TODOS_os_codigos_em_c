#ifndef DESENHA_ARVORE_PATRICIA_H
#define DESENHA_ARVORE_PATRICIA_H
#include "../ArvorePrefixo.h"

#define ESPACO 5

void desenhaArvorePatriciaRecursivo(NohPatricia *raiz, int depth, char *path, int right) {
    if (raiz == NULL) {
        return;
    }

    depth++;

    // Desenha a subarvore direita
    desenhaArvorePatriciaRecursivo(raiz->direita, depth, path, 1);

    // Atualiza o caminho para o no atual
    path[depth - 2] = 0;
    if (right) {
        path[depth - 2] = 1;
    }

    if (raiz->esquerda) {
        path[depth - 1] = 1;
    }

    // Exibe o no
    printf("\n");
    int i;
    for (i = 0; i < depth - 1; i++) {
        if (i == depth - 2)
            printf("+");
        else if (path[i])
            printf("|");
        else
            printf(" ");

        int j;
        for (j = 1; j < ESPACO; j++) {
            if (i < depth - 2)
                printf(" ");
            else
                printf("-");
        }
    }

    // Exibe o valor armazenado no no
    if (raiz->ehFolha) {
        printf("%s", raiz->chave);  // Exibe a chave, caso seja um no folha
    } else {
        printf("Bit Index: %d", raiz->bitIndex);  // Exibe o indice de bit, caso seja um no interno
    }

    // Desenha a subarvore esquerda
    for (i = 0; i < depth; i++) {
        if (path[i])
            printf(" ");
        else
            printf(" ");

        int j;
        for (j = 1; j < ESPACO; j++) {
            printf(" ");
        }
    }

    desenhaArvorePatriciaRecursivo(raiz->esquerda, depth, path, 0);
}

// Funcao para desenhar a arvore Patricia
void desenhaArvorePatricia(DPatricia *arvore) {
    char path[255] = {};

    desenhaArvorePatriciaRecursivo(arvore->raiz, 0, path, 0);
    printf("\n");
}

#endif
