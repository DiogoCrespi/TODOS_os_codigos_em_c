#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "ArvorePatricia.h"
#include "TAD_Arvore_PATRICIA.h"

void imprimirPalavra(const char *chave) {
    printf("%s", chave);
}

int main() {
    pDPatricia arvore = criarArvorePatricia();

    printf("Inserindo palavras com prefixos semelhantes na árvore Patricia:\n");
    adicionarChavePatricia(arvore, "computador");
    adicionarChavePatricia(arvore, "componente");
    adicionarChavePatricia(arvore, "compacto");
    adicionarChavePatricia(arvore, "comparar");
    adicionarChavePatricia(arvore, "compilar");
    adicionarChavePatricia(arvore, "companhia");

    printf("\nBuscando palavras:\n");
    printf("Busca 'computador': %d\n", buscarChavePatricia(arvore, "computador"));
    printf("Busca 'compilar': %d\n", buscarChavePatricia(arvore, "compilar"));

    printf("\nImprimindo a árvore Patricia:\n");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nRemovendo a palavra 'compacto':\n");
    removerChavePatricia(arvore, "compacto");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nRemovendo a palavra 'componente':\n");
    removerChavePatricia(arvore, "componente");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nTentando remover uma palavra inexistente 'computação':\n");
    int resultado = removerChavePatricia(arvore, "computação");
    printf("Resultado da remoção: %d\n", resultado);
    desenharArvorePatricia(arvore, imprimirPalavra);

    return 0;
}