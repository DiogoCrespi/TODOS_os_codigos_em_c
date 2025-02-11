#ifndef STRUCT_ARVORE_H
#define STRUCT_ARVORE_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Estrutura do noh da PATRICIA
struct nohPatricia {
    int ehFolha; // 1 se for folha, 0 se for noh interno
    int bitIndex; // Bit usado para comparacao
    char *chave; // Apenas para nos folha
    struct nohPatricia *esquerda, *direita;
};
typedef struct nohPatricia NohPatricia;

#endif
