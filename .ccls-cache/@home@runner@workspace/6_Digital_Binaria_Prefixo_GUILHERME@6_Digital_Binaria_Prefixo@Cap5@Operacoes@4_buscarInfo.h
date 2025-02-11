#ifndef BUSCAR_INFO_PATRICIA_H
#define BUSCAR_INFO_PATRICIA_H
#include "../ArvorePrefixo.h"
#include "../Utils.h"
#include <string.h> // Para strcmp
#include <stdlib.h> // Para NULL
#include <stdio.h>  // Para printf (depuracao)

int buscarInfoPatriciaRecursivo(NohPatricia *noh, const char *chave, int *L) {
    (*L)++; // Incrementa o nivel de profundidade
    printf("\n=== Nivel de profundidade: %d ===\n", *L);

    // Caso base: no folha
    if (noh->ehFolha) {
        printf("No folha encontrado.\n");
        printf("Comparando chave armazenada: %s\n", noh->chave);
        printf("Comparando com a chave buscada: %s\n", chave);
        return strcmp(noh->chave, chave) == 0;
    }

    // Obter o valor do bit correspondente ao indice do no
    int bit = obterBit(chave, noh->bitIndex);  // Usando a funcao corrigida
    printf("Comparando o bit %d da chave %s com o bitIndex %d do no.\n", bit, chave, noh->bitIndex);

    // Determina o proximo no com base no valor do bit
    if (bit == 0) {
        printf("A chave pertence a subarvore esquerda.\n");
        return buscarInfoPatriciaRecursivo(noh->esquerda, chave, L);
    } else {
        printf("A chave pertence a subarvore direita.\n");
        return buscarInfoPatriciaRecursivo(noh->direita, chave, L);
    }
}



// Funcao publica para buscar uma chave na PATRICIA
int buscarInfoPatricia(DPatricia *arvore, const char *chave) {
    if (arvore->raiz == NULL) {
        printf("\n=== Arvore vazia ===\n");
        return 0; // Arvore vazia
    }

    int L = -1; // Profundidade inicial
    printf("\n=== Iniciando a busca pela chave: %s ===\n", chave);
    return buscarInfoPatriciaRecursivo(arvore->raiz, chave, &L);
}

#endif
