#ifndef DESENHA_ARVORE_PATRICIA_H
#define DESENHA_ARVORE_PATRICIA_H

#include <stdio.h>
#include "../ArvorePatricia.h"

#define ESPACO 5
 

void desenharArvorePatriciaRecursivo(pNohPatricia raiz, int profundidade, char *caminho, int direita, FuncaoImpressao fi)
{
    if (raiz == NULL)
        return;

    profundidade++;

    desenharArvorePatriciaRecursivo(raiz->direita, profundidade, caminho, 1, fi);

    caminho[profundidade - 2] = 0;
    if (direita)
        caminho[profundidade - 2] = 1;

    if (profundidade > 1)
    {
        for (int i = 0; i < profundidade - 1; i++)
        {
            if (i == profundidade - 2)
                printf("+");
            else if (caminho[i])
                printf("|");
            else
                printf(" ");

            for (int j = 1; j < ESPACO; j++)
                if (i < profundidade - 2)
                    printf(" ");
                else
                    printf("-");
        }
    }

    if (raiz->ehFolha)
        fi(raiz->chave);
    else
        printf("%d", raiz->indice);
    printf("\n");

    desenharArvorePatriciaRecursivo(raiz->esquerda, profundidade, caminho, 0, fi);
}

void desenharArvorePatricia(pDPatricia arvore, FuncaoImpressao fi)
{
    if (arvore == NULL || arvore->raiz == NULL)
        return;

    char caminho[255] = {0};
    desenharArvorePatriciaRecursivo(arvore->raiz, 0, caminho, 0, fi);
}

#endif
