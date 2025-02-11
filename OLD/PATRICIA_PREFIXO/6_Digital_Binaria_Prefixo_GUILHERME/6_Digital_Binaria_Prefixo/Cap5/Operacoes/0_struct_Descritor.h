#ifndef STRUCT_DESCRITOR_ARVORE_H
#define STRUCT_DESCRITOR_ARVORE_H
#include "../ArvorePrefixo.h"

// Estrutura do descritor da PATRICIA
struct dPatricia {
    NohPatricia *raiz;
    int quantidadeChaves; // Numero de chaves na arvore
};
typedef struct dPatricia DPatricia;

#endif
