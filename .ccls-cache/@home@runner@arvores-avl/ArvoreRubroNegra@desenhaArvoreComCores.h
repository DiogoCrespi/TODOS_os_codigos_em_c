#ifndef DESENHA_ARVORE_COM_CORES_H
#define DESENHA_ARVORE_COM_CORES_H
#include "ArvoreRubroNegra.h"
#include "Utils.h"
#include <stdio.h> 
#define ESPACO 5

// Códigos de cor ANSI para vermelho e cinza
#define VERMELHO "\033[1;31m"
#define PRETO "\033[1;90m"
#define RESET "\033[0m"

void desenhaArvoreRecursivoComCores(pNoRubroNegra raiz, int depth, char *path, int right, FuncaoImpressao fi) {

    if (raiz == NULL)
        return;

    depth++;

    desenhaArvoreRecursivoComCores(raiz->direita, depth, path, 1, fi);

    path[depth-2] = 0;

    if(right)
        path[depth-2] = 1;

    if(raiz->esquerda)
        path[depth-1] = 1;

    printf("\n");
    int i;
    for(i=0; i<depth-1; i++)
    {
        if(i == depth-2)
            printf("+");
        else if(path[i])
            printf("|");
        else
            printf(" ");

        int j;
        for(j=1; j<ESPACO; j++)
        if(i < depth-2)
            printf(" ");
        else
            printf("-");
    }

    // Alterar a cor do nó com base na sua cor (VERMELHO ou PRETO)
    if (raiz->cor == VERMELHO) {
        printf(VERMELHO);
    } else {
        printf(PRETO);
    }

    fi(raiz->valor); // Imprime o valor do nó
    printf("[%s]", raiz->cor == VERMELHO ? "Vermelho" : "Preto"); // Exibe a cor textual

    // Resetar cor após imprimir o nó
    printf(RESET);

    desenhaArvoreRecursivoComCores(raiz->esquerda, depth, path, 0, fi);
}

void desenhaArvoreComCores(pArvoreRubroNegra arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRecursivoComCores(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}

#endif
