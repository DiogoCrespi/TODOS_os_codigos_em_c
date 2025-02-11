#include <stdio.h>
#include <string.h>
#include "Utils.h"
#include "ArvorePatricia.h"
#include "TAD_Arvore_PATRICIA.h"

void imprimirPalavra(void *chave) {
    printf("%s", (const char *)chave);
}

int main() {
    pDPatricia arvore = criarArvorePatricia();

    printf("Inserindo palavras com prefixos semelhantes na arvore Patricia:\n");
    adicionarChavePatricia(arvore, "computador");
    adicionarChavePatricia(arvore, "componente");
    adicionarChavePatricia(arvore, "compacto");
    adicionarChavePatricia(arvore, "comparar");
    adicionarChavePatricia(arvore, "compilar");
    adicionarChavePatricia(arvore, "companhia");

    printf("\nBuscando palavras:\n");
    printf("Busca 'computador': %d\n", buscarChavePatricia(arvore, "computador"));
    printf("Busca 'compilar': %d\n", buscarChavePatricia(arvore, "compilar"));

    printf("\nImprimindo a arvore Patricia:\n");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nRemovendo a palavra 'compacto':\n");
    removerChavePatricia(arvore, "compacto");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nRemovendo a palavra 'componente':\n");
    removerChavePatricia(arvore, "componente");
    desenharArvorePatricia(arvore, imprimirPalavra);

    printf("\nTentando remover uma palavra inexistente 'computacao':\n");
    int resultado = removerChavePatricia(arvore, "computacao");
    printf("Resultado da remocao: %d\n", resultado);
    desenharArvorePatricia(arvore, imprimirPalavra);

    return 0;
}
