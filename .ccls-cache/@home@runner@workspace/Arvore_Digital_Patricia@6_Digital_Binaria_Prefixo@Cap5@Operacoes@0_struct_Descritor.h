
#ifndef STRUCT_DESCRITOR_ARVORE_PATRICIA_H
#define STRUCT_DESCRITOR_ARVORE_PATRICIA_H

#include "../ArvorePatricia.h"

struct dPatricia {
    struct nohPatricia* raiz;  // Raiz da árvore
    int quantidadeNohs;       // Contador de nós
};

#endif