#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "ArvorePatricia.h"

int main()
{
    pDPatricia arvore = criarArvorePatricia();

    printf("Inserindo chaves na árvore Patricia:\n");
    adicionarChavePatricia(arvore, "1010");
    adicionarChavePatricia(arvore, "1011");
    adicionarChavePatricia(arvore, "0010");
    adicionarChavePatricia(arvore, "1100");
    adicionarChavePatricia(arvore, "1111");

    printf("\nBuscando chaves:\n");
    printf("Busca '1010': %d\n", buscarChavePatricia(arvore, "1010"));
    printf("Busca '1100': %d\n", buscarChavePatricia(arvore, "1100"));

    printf("\nImprimindo a árvore:\n");
    desenharArvorePatricia(arvore, imprimirChar);

    printf("\nRemovendo a chave '1011':\n");
    removerChavePatricia(arvore, "1011");
    desenharArvorePatricia(arvore, imprimirChar);

    printf("\nRemovendo a chave '0010':\n");
    removerChavePatricia(arvore, "0010");
    desenharArvorePatricia(arvore, imprimirChar);

    printf("\nTentando remover uma chave inexistente '0000':\n");
    int resultado = removerChavePatricia(arvore, "0000");
    printf("Resultado da remoção: %d\n", resultado);
    desenharArvorePatricia(arvore, imprimirChar);

    return 0;
}
