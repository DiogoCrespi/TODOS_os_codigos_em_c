#ifndef DESENHA_ARVORE_SEM_CORES_H
#define DESENHA_ARVORE_SEM_CORES_H
#include "ArvoreRubroNegra.h"
#include "Utils.h"
#include <stdio.h> 
#define ESPACO 5

void desenhaArvoreRecursivoSemCores(pNoRubroNegra raiz, int depth, char *path, int right, FuncaoImpressao fi) {

    if (raiz == NULL)
        return;

    depth++;

    desenhaArvoreRecursivoSemCores(raiz->direita, depth, path, 1, fi);

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

    fi(raiz->valor); // Imprime o valor do nó
    printf("[%s]", raiz->cor == VERMELHO ? "Vermelho" : "Preto"); // Exibe a cor do nó sem usar cores no terminal

    desenhaArvoreRecursivoSemCores(raiz->esquerda, depth, path, 0, fi);
}

void desenhaArvoreSemCores(pArvoreRubroNegra arvore, FuncaoImpressao fi) {
    char path[255] = {};

    desenhaArvoreRecursivoSemCores(arvore->raiz, 0, path, 0, fi);
    printf("\n");
}

#endif
