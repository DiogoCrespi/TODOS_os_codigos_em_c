#ifndef DESENHA_ARVORE_RUBRO_H
#define DESENHA_ARVORE_RUBRO_H
#include "../ArvoreRubroNegra.h"
#define ESPACO 5

void desenhaArvoreRecursivo(pNohArvore raiz, int profundidade, char *path, int direita, FuncaoImpressao fi, pNohArvore sentinela)
{
    if (raiz == sentinela || raiz == NULL)
        return;

    profundidade++;

    desenhaArvoreRecursivo(raiz->direita, profundidade, path, 1, fi, sentinela);

    path[profundidade - 2] = 0;

    if (direita)
        path[profundidade - 2] = 1;

    if (raiz->esquerda != sentinela)
        path[profundidade - 1] = 1;

    printf("\n");

    for (int i = 0; i < profundidade - 1; i++)
    {
        if (i == profundidade - 2)
            printf("+");
        else if (path[i])
            printf("|");
        else
            printf(" ");

        for (int j = 1; j < ESPACO; j++)
            printf(i < profundidade - 2 ? " " : "-");
    }

    fi(raiz->info);
    printf("[%c]", raiz->cor == RED ? 'R' : 'B');

    desenhaArvoreRecursivo(raiz->esquerda, profundidade, path, 0, fi, sentinela);
}

void desenhaArvore(pDArvore arvore, FuncaoImpressao fi)
{
    if (arvore == NULL || arvore->raiz == NULL)
    {
        printf("Árvore vazia!\n");
        return;
    }

    char path[255] = {0};
    desenhaArvoreRecursivo(arvore->raiz, 0, path, 0, fi, arvore->sentinela);
    printf("\n");
}

#endif
